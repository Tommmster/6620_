static unsigned int
ratoi(unsigned int acc, char *e)
{
  const unsigned int i = *e - '0';
  if (! *e ){
  	return acc;
  }
  else {
  	if ( i > 9) {
  		return acc;
  	}
  	else return ratoi( acc * 10 + i, e + 1);
  }
}
unsigned int
atoi(const char *s)
{
  char *p = (char *) s;

  if (!*p){
  	return 0;
  }
  else {
    return ratoi(*p - '0', p + 1);
  }
}

