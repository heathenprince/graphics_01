#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {

	int r, g, b = 255;
	int i,j,x = 0;
	
	int fd = open("hi.ppm", O_CREAT | O_TRUNC | O_RDWR, 0644 );
	
	int xres = 500;
	int yres = 500;
	
	char str[100];
  sprintf(str, "P3\n");
  write(fd, str, strlen(str));
  sprintf(str, "%d %d 255\n",xres,yres);
  write(fd, str, strlen(str));


	for( j = 0; j < yres; j++ ) {
		for( i = 0; i < xres; i++ ) {

			if( ((yres / 2) - j <= 20 && (yres / 2) - j >= -20) || ((xres / 2) - i <=20 && (xres / 2) - i >= -20 )) { //red plus +
					r = 255;
					g = 0;
					b = 0;
			}
			 
			else if( ((yres / 2) - j <= 30 && (yres / 2) - j >= -30) || ((xres / 2) - i <= 30 && (xres / 2) - i >= -30 )) { //white plus +
				r = 255;
				g = 255;
				b = 255;
			}

			else if( i >= j-10 && i <= j+10 ) { //red cross x
				r = 255;
				g = 0;
				b = 0;
			} 

			else if( i >= j-30 && i <= j+30 ) { // white cross x
				r = 255;
				g = 255;
				b = 255;
			}

			else if( i + j >= yres-10 && i +j <= yres+10) {
				r = 255;
				g = 0;
				b = 0;
			}
			
			else if( i + j >= yres-30 && i +j <= yres+30) { 
				r = 255;
				g = 255;
				b = 255;
			}

			else { //blue bg
				r = 0;
				g = 0;
				b = 255;
			}
			sprintf(str, "%d %d %d\n", r, g, b);
			write(fd, str, strlen(str));	
		}
	}
	close(fd);
	return 0;
}
