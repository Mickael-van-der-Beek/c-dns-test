#include <stdio.h>
#include <netdb.h>

int main (void) {
  struct addrinfo *result;
  struct addrinfo *rp;
  int code;

  code = getaddrinfo("google", NULL, NULL, &result);

  if (code != 0) {
    fprintf(stderr, "getaddrinfo: %s (%d)\n", gai_strerror(code), code);
  } else {
    char addr[1024];

    for (rp = result; rp != NULL; rp = rp->ai_next) {
      code = getnameinfo(
        rp->ai_addr,
        rp->ai_addrlen,
        addr,
        sizeof addr,
        NULL,
        0,
        NI_NUMERICHOST
      );

      if (code != 0) {
        fprintf(stderr, "getnameinfo: %s (%d)\n", gai_strerror(code), code);
      } else {
        printf("addr: %s\n", addr);
      }
    }

    freeaddrinfo(result);
  }

  return 0;
}
