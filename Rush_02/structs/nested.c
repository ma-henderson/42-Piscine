typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} pixel;

typedef struct {
	int width;
	int height;
	pixel *data;
} screen;

screen* new_screen(int height, int width)
{
	screen *s = malloc(sizeof(screen));
	s->width = width;
	s->height = height;
	s->data = malloc(sizeof(pixel) * width * height);

	return (s);
}

void screen_free(screen *s)
{
	free(s->data);:
	free(s);
}

int main()
{
	pixel p = {0, 0, 127};
	
	return (0);
}
