#include <stdio.h>
#include <stdlib.h>
#include <sys/____.h>              /* open() */
#include <sys/____.h>              /* open() */
#include <____.h>               /* open() */
#include <____.h>               /* read() y write() , close() */

char buffer[BUFSIZ]; /*Buffer para manipular datos. */

int main(int argc, char *argv___)
{
   int fd_origen; int fd_destino; int nbytes;
   int i;

   /*Analisis de los argumentos de la linea de comandos*/
   if (argc <= ____) {
     fprintf(stderr,"Forma de uso: %s ______ \n", argv[____]);
	 exit(____);
   }

   /* Apertura o creacion de archivos en modo solo escritura. */
   /* Abrir en modo solo Lectura (O_WRONLY). */
   /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
   /* El archivo es creado en caso de que no exista (O_CREAT). */
   /* El modo que se crea es 0666. */
   if ((fd_destino= ____(argv[____-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1) {
	  fprintf(stderr,"Error al crear el archivo de salida \n");
	 perror(argv[3]);
	 exit(____);
   }

   for(____;i<3;i++)  {

   /*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
   if ((fd_origen=open(____,O_RDONLY))== -1) {
	  fprintf(stderr,"Error al abrir el archivo de entrada: %s ¥n", ____);
	  perror(argv[1]);
	  exit(____);
   }

   /* copiamos el archivo 1 en el archivo destino. */
   while ((nbytes=read(____, buffer, sizeof buffer))> 0)
	 write(____, buffer, nbytes);
	 close(____);
   }

   close(____);
}