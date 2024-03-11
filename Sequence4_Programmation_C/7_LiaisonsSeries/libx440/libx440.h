#ifndef __LIB_X440_H__
#define __LIB_X440_H__

#include <termios.h>

int serial_open(const char *device, int baudrate);
int serial_close(int fd);
int serial_write(int fd, const char *data);
int serial_read(int fd, char *data, int len);
char get_relay_status(int fd, unsigned short int relay);
int set_relay_status(int fd, unsigned short int relay, unsigned short int status);
int set_input_mode(int fd, unsigned short int input, char mode);
char *serial_get_version(void);
  
#endif /* __LIB_X440_H__ */
