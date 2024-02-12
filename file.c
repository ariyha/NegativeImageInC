#include <stdio.h>

int main() {
    int i, j;
    FILE *fp = fopen("D:/c/projects/images/image.bmp", "rb");
    FILE *fp2 = fopen("D:/c/projects/images/output.bmp", "wb");
    unsigned char header[54];
    unsigned char colorTable[1024];
    unsigned char r, g, b;
    fread(header, sizeof(unsigned char), 54, fp);
    fwrite(header, sizeof(unsigned char), 54, fp2);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    printf("%d,%d,%d",width,height,bitDepth);
   
    if (bitDepth <= 8) 
    {
        fread(colorTable, sizeof(unsigned char), 1024, fp);
        fwrite(colorTable, sizeof(unsigned char), 1024, fp2);
        for (i = 0; i < width; i++) 
        {
            for (j = 0; j < height; j++) 
            {
                r=fgetc(fp);
                fputc((255-r),fp2);
            }}} 

    else 
    {
        for (i = 0; i < height; i++) 
        {
            for (j = 0; j < width ; j += 1) 
            {
                r = fgetc(fp);
                g = fgetc(fp);
                b = fgetc(fp); 
                fputc((255-r), fp2);
                fputc((255-g), fp2);
                fputc((255-b), fp2);
            }
        }
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}
