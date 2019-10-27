1.

name@computer:~/operativos/practica7$ diff -Naur fus.c fusionar.c
--- fus.c       2019-10-16 15:21:03.637024700 -0500
+++ fusionar.c  2019-10-16 15:17:59.340064600 -0500
@@ -1,51 +1,55 @@
+/* PROGRAMA: copiar.c
+ FORMA DE USO:
+       ./copiar origen destino
+ VALOR DE RETORNO:
+       0: si se ejecuta satisfactoriamente.
+       -1: si se da alguna condicion de error
+*/

 #include <stdio.h>
 #include <stdlib.h>
-#include <sys/__.h>              /* open() */
-#include <sys/__.h>              /* open() */
-#include <__.h>               /* open() */
-#include <__.h>               /* read() y write() , close() */
+#include <sys/types.h> /* open() /
+#include <sys/stat.h>  /* open() /
+#include <fcntl.h>     /* open() /
+#include <unistd.h>    /* read() y write() */

 char buffer[BUFSIZ]; /*Buffer para manipular datos. */

-int main(int argc, char *argv___)
+main(int argc, char *argv[])
 {
-   int fd_origen; int fd_destino; int nbytes;
-   int i;
+   int fd_origen;
+   int fd_destino;
+   int nbytes;

    /Analisis de los argumentos de la linea de comandos/
-   if (argc <= __) {
-     fprintf(stderr,"Forma de uso: %s __ \n", argv[__]);
-        exit(__);
+   if (argc != 3)
+   {
+      fprintf(stderr,"Forma de uso: %s origen destino\n", argv[0]);
+      exit(-1);
+   }
+
+   /*Apertura del archivo en modo solo lectura (O_RDONLY). */
+if ((fd_origen=open(argv[1],O_RDONLY))== -1)
+   {
+      perror(argv[1]);
+      exit(-1);
    }

    /* Apertura o creacion de archivos en modo solo escritura. */
    /* Abrir en modo solo Lectura (O_WRONLY). */
-   /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
+   /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC).*/
    /* El archivo es creado en caso de que no exista (O_CREAT). */
    /* El modo que se crea es 0666. */
-   if ((fd_destino= _(argv[_-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1) {
-         fprintf(stderr,"Error al crear el archivo de salida \n");
-        perror(argv[3]);
-        exit(__);
-   }
-
-   for(__;i<3;i++)  {
-
-   /*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
-   if ((fd_origen=open(__,O_RDONLY))== -1) {
-         fprintf(stderr,"Error al abrir el archivo de entrada: %s ¥n", __);
-         perror(argv[1]);
-         exit(__);
-   }
-
-   /* copiamos el archivo 1 en el archivo destino. */
-   while ((nbytes=read(__, buffer, sizeof buffer))> 0)
-        write(__, buffer, nbytes);
-        close(__);
+   if ((fd_destino=open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0666))== -1)
+   {
+      perror(argv[2]);
+      exit(-1);
    }

-   close(__);
-}
-
+   /* copiamos el archivo origen en el archivo destino. */
+   while ((nbytes=read(fd_origen, buffer, sizeof buffer))> 0)
+      write(fd_destino, buffer, nbytes);
+   close(fd_origen);
+   close(fd_destino);
+ }



2.

name@computer:~/operativos/practica7$ diff -Naur fus.c preg2.c
--- fus.c       2019-10-16 15:21:03.637024700 -0500
+++ preg2.c     2019-10-16 15:30:21.697336000 -0500
@@ -1,51 +1,195 @@
+#include <stdio.h>
+
+#include <stdlib.h>
+
+#include <sys/types.h> /* open() */
+
+#include <sys/stat.h>  /* open() */
+
+#include <fcntl.h>     /* open() */
+
+#include <unistd.h>    /* read() y write() , close() */
+
+
+
+char buffer[BUFSIZ]; /*Buffer para manipular datos. */
+
+
+
+main(int argc, char *argv[])
+
+{
+
+int fd_origen; int fd_destino; int nbytes;
+
+
+
+/Analisis de los argumentos de la linea de comandos/
+
+
+
+if (argc <= 3)
+
+{
+
+fprintf(stderr,"Forma de uso: %s archivos (separados con espacios) destino\n", argv[0]);
+
+exit(-1);
+
+}
+
+
+
+/* Apertura o creacion de archivos en modo solo escritura. */
+
+/* Abrir en modo solo Lectura (O_WRONLY). */
+
+/* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
+
+/* El archivo es creado en caso de que no exista (O_CREAT). */
+
+/* El modo que se crea es 0666. */
+
+
+
+if ((fd_destino= open(argv[argc-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1)
+
+{
+
+fprintf(stderr,"Error al crear el archivo de salida \n");
+
+perror(argv[argc-1]);
+
+exit(-1);
+
+}
+
+
+
+int i;
+
+for(i =1;i<argc-1;i++) {
+
+/*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
+
+       if ((fd_origen=open(argv[i],O_RDONLY))== -1) {
+
+               fprintf(stderr,"Error al abrir el archivo de entrada: %s \n", argv[i]);
+
+               perror(argv[i]);
+
+               exit(-1);
+
+       }
+
+/* copiamos el archivo 1 en el archivo destino. */
+
+       while ((nbytes=read(fd_origen, buffer, sizeof buffer))> 0)
+
+               write(fd_destino, buffer, nbytes);
+
+               close(fd_origen);
+
+       }
+
+       close(fd_destino);
+
+}

 #include <stdio.h>
+
 #include <stdlib.h>
-#include <sys/__.h>              /* open() */
-#include <sys/__.h>              /* open() */
-#include <__.h>               /* open() */
-#include <__.h>               /* read() y write() , close() */
+
+#include <sys/types.h> /* open() */
+
+#include <sys/stat.h>  /* open() */
+
+#include <fcntl.h>     /* open() */
+
+#include <unistd.h>    /* read() y write() , close() */
+
+

 char buffer[BUFSIZ]; /*Buffer para manipular datos. */

-int main(int argc, char *argv___)
+
+
+main(int argc, char *argv[])
+
+{
+
+int fd_origen; int fd_destino; int nbytes;
+
+
+
+/Analisis de los argumentos de la linea de comandos/
+
+
+
+if (argc <= 3)
+
+{
+
+fprintf(stderr,"Forma de uso: %s archivos (separados con espacios) destino\n", argv[0]);
+
+exit(-1);
+
+}
+
+
+
+/* Apertura o creacion de archivos en modo solo escritura. */
+
+/* Abrir en modo solo Lectura (O_WRONLY). */
+
+/* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
+
+/* El archivo es creado en caso de que no exista (O_CREAT). */
+
+/* El modo que se crea es 0666. */
+
+
+
+if ((fd_destino= open(argv[argc-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1)
+
 {
-   int fd_origen; int fd_destino; int nbytes;
-   int i;

-   /Analisis de los argumentos de la linea de comandos/
-   if (argc <= __) {
-     fprintf(stderr,"Forma de uso: %s __ \n", argv[__]);
-        exit(__);
-   }
-
-   /* Apertura o creacion de archivos en modo solo escritura. */
-   /* Abrir en modo solo Lectura (O_WRONLY). */
-   /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
-   /* El archivo es creado en caso de que no exista (O_CREAT). */
-   /* El modo que se crea es 0666. */
-   if ((fd_destino= _(argv[_-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1) {
-         fprintf(stderr,"Error al crear el archivo de salida \n");
-        perror(argv[3]);
-        exit(__);
-   }
-
-   for(__;i<3;i++)  {
-
-   /*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
-   if ((fd_origen=open(__,O_RDONLY))== -1) {
-         fprintf(stderr,"Error al abrir el archivo de entrada: %s ¥n", __);
-         perror(argv[1]);
-         exit(__);
-   }
-
-   /* copiamos el archivo 1 en el archivo destino. */
-   while ((nbytes=read(__, buffer, sizeof buffer))> 0)
-        write(__, buffer, nbytes);
-        close(__);
-   }
+fprintf(stderr,"Error al crear el archivo de salida \n");
+
+perror(argv[argc-1]);
+
+exit(-1);
+
+}
+
+
+int i;
+
+for(i =1;i<argc-1;i++) {
+
+/*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
+
+       if ((fd_origen=open(argv[i],O_RDONLY))== -1) {
+
+               fprintf(stderr,"Error al abrir el archivo de entrada: %s \n", argv[i]);
+
+               perror(argv[i]);
+
+               exit(-1);
+       }
+
+/* copiamos el archivo 1 en el archivo destino. */
+
+       while ((nbytes=read(fd_origen, buffer, sizeof buffer))> 0)
+
+               write(fd_destino, buffer, nbytes);
+
+               close(fd_origen);
+
+       }
+
+       close(fd_destino);

-   close(__);
 }





3. Cambiar formato
Ejecucion de copiar.c   0.020-0.090s
Ejecucion de cp -  0.004-0.006 s
 
 
 
name@pc:~/operativos/practica7$ time cp hello.cpp helloCopia.cpp
 
real    0m0.020s
user    0m0.000s
sys     0m0.000s
name@pc:~/operativos/practica7$ time ./copiar hello.cpp hellooCopia.cpp
 
real    0m0.006s
user    0m0.000s
sys     0m0.000s
 

4. cambia fecha(minutos, milisegundos)
name@pc:~/operativos/practica7$ diff -Naur fus.c fusionar._sync.c
--- fus.c       2019-10-16 15:21:03.637024700 -0500
+++ fusionar._sync.c    1969-12-31 18:00:00.000000000 -0600
@@ -1,51 +0,0 @@
-
-#include <stdio.h>
-#include <stdlib.h>
-#include <sys/__.h>              /* open() */
-#include <sys/__.h>              /* open() */
-#include <__.h>               /* open() */
-#include <__.h>               /* read() y write() , close() */
-
-char buffer[BUFSIZ]; /*Buffer para manipular datos. */
-
-int main(int argc, char *argv___)
-{
-   int fd_origen; int fd_destino; int nbytes;
-   int i;
-
-   /Analisis de los argumentos de la linea de comandos/
-   if (argc <= __) {
-     fprintf(stderr,"Forma de uso: %s __ \n", argv[__]);
-        exit(__);
-   }
-
-   /* Apertura o creacion de archivos en modo solo escritura. */
-   /* Abrir en modo solo Lectura (O_WRONLY). */
-   /* Si el archivo existe entonces truncar a cero bytes (O_TRUNC)*/
-   /* El archivo es creado en caso de que no exista (O_CREAT). */
-   /* El modo que se crea es 0666. */
-   if ((fd_destino= _(argv[_-1], O_WRONLY|O_TRUNC|O_CREAT, 0666))==-1) {
-         fprintf(stderr,"Error al crear el archivo de salida \n");
-        perror(argv[3]);
-        exit(__);
-   }
-
-   for(__;i<3;i++)  {
-
-   /*Apertura del archivo 1 en modo solo lectura (O_RDONLY). */
-   if ((fd_origen=open(__,O_RDONLY))== -1) {
-         fprintf(stderr,"Error al abrir el archivo de entrada: %s ¥n", __);
-         perror(argv[1]);
-         exit(__);
-   }
-
-   /* copiamos el archivo 1 en el archivo destino. */
-   while ((nbytes=read(__, buffer, sizeof buffer))> 0)
-        write(__, buffer, nbytes);
-        close(__);
-   }
-
-   close(__);
-}
-
-



5.Recuerda cambiar lo de nombres y tiempos, nombres de los documentos no crack

name@computer:~/operativos/practica7$ time ./fusionar.c hello.cpp helloCopia.cpp

real    0m0.039s
user    0m0.000s
sys     0m0.031s


name@computer:~/operativos/practica7$ time ./fusionar_sync.c hello.cpp helloCopia.cpp

real    0m0.168s
user    0m0.016s
sys     0m0.125s


6. Cambien estoo

La diferencia radica en la sincronizacion que exige mas tiempo por parte de la computadora al hacer operaciones de I/O ya que tiene que esperar a que termine una lectura para hacer una esctiruta y viceversa