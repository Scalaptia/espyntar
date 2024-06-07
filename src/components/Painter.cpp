#include "../headers/Painter.h"

Painter::Painter(ColorPalette &palette, Canvas &canvas) : palette(palette), canvas(canvas)
{
    brushSize = 20.0f;
    currentColor = 0;
    lastPosition = {-1.0f, -1.0f};
}

void Painter::Paint(Vector2 position)
{
    position.x -= GetScreenWidth() / 2.0f - canvas.GetTarget().texture.width / 2.0f;
    position.y -= GetScreenHeight() / 2.0f - canvas.GetTarget().texture.height / 2.0f;

    if (lastPosition.x >= 0 && lastPosition.y >= 0)
    {
        // Interpolate between lastPosition and position
        for (float t = 0.0f; t < 1.0f; t += 0.05f)
        {
            Vector2 interpolatedPosition;
            interpolatedPosition.x = lastPosition.x * (1 - t) + position.x * t;
            interpolatedPosition.y = lastPosition.y * (1 - t) + position.y * t;
            canvas.Draw(interpolatedPosition, brushSize, palette.GetColor(currentColor));
        }
    }
    else
    {
        canvas.Draw(position, brushSize, palette.GetColor(currentColor));
    }

    lastPosition = position;
}

void Painter::SetBrushSize(float delta)
{
    delta *= 2.0f;

    brushSize += delta;
    if (brushSize < 1.0f)
        brushSize = 1.0f;

    if (brushSize > 100.0f)
        brushSize = 100.0f;
}

void Painter::Fill(Vector2 position)
{
    canvas.BucketFill(position, GetColor());
}