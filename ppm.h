#ifndef PPM_H
#define PPM_H

/*
	ppm_pixel : un pixel (r, g, b)
*/
struct ppm_pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

/*
	ppm_image_setpixel() : définit la couleur d’un pixel
*/
static inline void ppm_setpixel(
		struct ppm_pixel *px,
		unsigned char r, unsigned char g, unsigned char b)
{
	px->r = r;
	px->g = g;
	px->b = b;
}

/*
	ppm_image : une image (largeur, hauteur, tableau de pixels)
*/
struct ppm_image {
	unsigned int width;
	unsigned int height;
	struct ppm_pixel *px;
};

/*
	ppm_image_init()     : initialise une image
*/
int ppm_image_init(struct ppm_image *im, int w, int h);
/*
	ppm_image_release()  : libère la mémoire
*/
int ppm_image_release(struct ppm_image *im);

static inline void ppm_image_setpixel(
		struct ppm_image *im, int x, int y,
		unsigned char r, unsigned char g, unsigned char b)
{
	struct ppm_pixel *px = im->px + im->width * y + x;
	ppm_setpixel(px, r, g, b);
}

/*
	ppm_image_dump()     : écrit l’image dans un fichier .ppm
*/
int ppm_image_dump(struct ppm_image *im, char *path);


#endif // PPM_H
