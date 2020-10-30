
extern char* out;

int
encode(char *input,  unsigned int len)
{ 
  static char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  
  unsigned int i1 = (unsigned int) input[0] >> 2;
  unsigned int i2 = (unsigned int) (input[0] & 0x3)  << 4 | input[1] >> 4;
  unsigned int i3 = (unsigned int) (input[1] & 0xF)  << 4 | input[2] >> 6;
  unsigned int i4 = (unsigned int) input[2] & 0x3F;

  out[0] = alphabet[i1];
  out[1] = alphabet[i2];
  out[2] = alphabet[i3];
  out[3] = alphabet[i4];

  return 0; /* OK */

}
