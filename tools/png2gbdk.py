from PIL import Image
import sys

def png_to_gbdk_c(png_file, c_file, array_name="sprite"):
    # Open image
    img = Image.open(png_file).convert("L")  # Convert in greyscale

    # Normalise on 4 colors (0=white → 3=black)
    pixels = list(img.getdata())
    unique_vals = sorted(set(pixels))
    if len(unique_vals) > 4:
        raise ValueError("⚠️ Too much colors ! Use max 4 colors.")

    # Map greyscale → 0..3
    palette_map = {val: (3 - i) for i, val in enumerate(unique_vals)}

    # Convert in 2 plans (Game Boy format)
    data = []
    for y in range(8):
        byte1 = 0
        byte2 = 0
        for x in range(8):
            color = palette_map[pixels[y * 8 + x]]
            bit = 7 - x  # bit from left to right

            # Each pixel → 2 bits
            if color & 1:
                byte1 |= (1 << bit)
            if color & 2:
                byte2 |= (1 << bit)

        data.append(byte1)
        data.append(byte2)

    # Process the .c
    with open(c_file, "w") as f:
        f.write(f"const unsigned char {array_name}[] = {{\n")
        f.write(f"//\tclang-format off\n")
        for i in range(0, len(data), 2):
            f.write(f"\t0b{data[i]:08b}, 0b{data[i+1]:08b},\n")
        f.write(f"//\tclang-format on\n")
        f.write("};\n")

    print(f"✅ Export finish → {c_file}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python png2gbdk.py input.png output.c [array_name]")
    else:
        array_name = sys.argv[3] if len(sys.argv) > 3 else "sprite"
        png_to_gbdk_c(sys.argv[1], sys.argv[2], array_name)
