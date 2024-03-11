/* =====================================
 * Object: Serial library for X440 board
 * Author: Loïc PLASSART
 * Date: October 5th 2022
 * Compilation: See Makefile
 * ====================================
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include "libx440.h"

#define VERSION "0.1"

/* ----------------------------- */
/* Etablissement de la connexion */
/* ----------------------------- */
int serial_open(const char *device, int baudrate)
{
  int fd;
  struct termios newtio;
  
  /* Ouverture du port série/USB */
  fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
 
  if (fd == -1)
  {
    fprintf(stderr, "libx440: Unable to open %s!", device);
    return -1;
  }
  
  /* Configuration des paramètres de connexion */
  tcgetattr (fd, &newtio);

  if (baudrate == 19200)
    newtio.c_cflag = B19200 | CS8 | CLOCAL | CREAD;
  else if (baudrate == 38400)
    newtio.c_cflag = B38400 | CS8 | CLOCAL | CREAD;
  else if (baudrate == 57600)
    newtio.c_cflag = B57600 | CS8 | CLOCAL | CREAD;
  else if (baudrate == 115200)
    newtio.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
  else
  {
    newtio.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
  }
  
  newtio.c_iflag = IGNPAR | ICRNL;
  newtio.c_oflag = 0;
  newtio.c_lflag = ~ICANON;
  newtio.c_cc[VEOL] = 0;

  tcflush(fd, TCIFLUSH);
  tcsetattr(fd, TCSANOW, &newtio);
  tcflush(fd, TCIFLUSH);
  fcntl(fd, F_SETFL, 0);

  return fd;
}

/* ------------------ */
/* Lecture de données */
/* ------------------ */
int serial_read(int fd, char *buff, int len)
{
  int ret;
  
  ret = read(fd, buff, len);
 
  if (ret < 0)
  {
    fprintf(stderr, "libx440: Unable to read data!");
    return -1;
  }

  return 0;
}

/* ------------------- */
/* Ecriture de données */
/* ------------------- */
int serial_write(int fd, const char *data)
{
  int ret;
  
  ret = write(fd, data, strlen(data));

  if (ret < 0)
  {
    fprintf(stderr, "libx440: Unable to send data!");
    return -1;
  }

   return 0; 
}


/* ---------------------------------- */
/* Récupération de l'état d'un relais */
/* ---------------------------------- */
char get_relay_status(int fd, unsigned short int relay)
{
  int ret[2];
  char buff[10];

  if ((relay < 1) || (relay > 4))
  {
    fprintf(stderr, "libx440: Invalid relay number!");
    return -1;
  }
  
  ret[0] = serial_write(fd, "?");
  ret[1] = serial_read(fd, buff, sizeof(buff));

  if ((ret[0] < 0) || (ret[1] < 0))
  {
    fprintf(stderr, "libx440: Unable to get relay status!");
    return -1;
  }

  return buff[6 - relay];
}


/* --------------------------------- */
/* Commutation de l'état d'un relais */
/* --------------------------------- */
int set_relay_status(int fd, unsigned short int relay, unsigned short int status)
{
  int ret;
  char buff[5];

  if ((relay < 1) || (relay > 4))
  {
    fprintf(stderr, "libx440: Invalid relay number!");
    return -1;
  }
  
  if ((status < 0) || (status > 1))
  {
    fprintf(stderr, "libx440: Invalid status value!");
    return -1;
  }

  sprintf(buff, "S%hu%hu", relay, status);
  ret = serial_write(fd, buff);

  if (ret < 0)
  {
    fprintf(stderr, "libx440: Unable to set relay status!");
    return -1;
  }
  
  return 0;
}


/* ------------------------------------------------- */
/* Forçage du mode analogique/numérique d'une entrée */
/* ------------------------------------------------- */
int set_input_mode(int fd, unsigned short int input, char mode)
{
  int ret;
  char buff[5];

  if ((input < 1) || (input > 4))
  {
    fprintf(stderr, "libx440: Invalid input number!");
    return -1;
  }
  
  if ((mode != 'D') && (mode != 'A'))
  {
    fprintf(stderr, "libx440: Invalid mode value!");
    return -1;
  }
  
  sprintf(buff, "IN%hu%c", input, mode);
  ret = serial_write(fd, buff);
  
  if (ret < 0)
  {
    fprintf(stderr, "libx440: Unable to set input mode!");
    return -1;
  }
  
  return 0;
}


/* ------------------------- */
/* Fermeture de la connexion */
/* ------------------------- */
int serial_close(int fd)
{
  int ret;

  ret = close(fd);

  if (ret < 0)
  {
    fprintf(stderr, "libx440: Unable to close connection!");
    return -1;
  }
  
  return 0;   
}

/* --------------------------------- */
/* Récupération du numéro de version */
/* --------------------------------- */
char *serial_get_version(void)
{
  return VERSION;
}

