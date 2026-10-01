from PIL import Image, ImageDraw, ImageFont

with open('output.txt') as f:
    lines = f.read().split('\n')

font = ImageFont.truetype(
    "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", 14)

# Ширина по самой длинной строке
max_width = max(font.getlength(line) for line in lines)
line_height = 20
width = int(max_width) + 40
height = line_height * len(lines) + 40

img = Image.new('RGB', (width, height), color='#1e1e1e')
draw = ImageDraw.Draw(img)

y = 20
for line in lines:
    # Красным — строки с WARNING / data race / SUMMARY
    if any(k in line for k in ('WARNING', 'data race', 'SUMMARY')):
        color = '#ff5555'
    else:
        color = '#d4d4d4'
    draw.text((20, y), line, font=font, fill=color)
    y += line_height

img.save('output.png')
print(f"Сохранено: output.png ({width}x{height})")