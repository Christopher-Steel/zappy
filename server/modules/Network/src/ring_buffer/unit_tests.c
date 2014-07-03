#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "ring_buf.h"
#include "print_debug.h"

int	main(void)
{
  t_ring_buf	*buffer;
  char		*pushedText;
  int		len;

  buffer = ring_buf_create();

  printf("Ring buffer created of length: %d and size: %d\n",
	 ring_buf_len(buffer), RING_BUF_SIZE);
  pushedText = strdup("This is a very long ring buffer test\n"
		      "Normally this thing should be long enough to overflow "
		      "the buffer's capacity but it will be a long winded "
		      "effort to attain such a lengthy text for simple debug "
		      "reasons. Nevertheless if shall try my best to "
		      "sustain interesting conversation with you as you read "
		      "my long and honestly quite random debug. You should "
		      "try this kind of exercise some time, it is quite an "
		      "interesting thing to let your mind flow through your "
		      "debug messages. I currently have no idea how long "
		      "this text i");
  printf("Pushed %d length string into buffer\n",
	 ring_buf_push(buffer, pushedText));
  printf("buffer length: %d\n", ring_buf_len(buffer));
  printf("%s\n", &buffer->buf[0]);
  char	*pop;

  printf("popped a string of length %d\n", (len = ring_buf_pop_alloc(buffer, &pop)));
  printf("%s\n", pop);
  if (len > 0)
    free(pop);
  printf("popped a string of length %d\n", (len = ring_buf_pop_alloc(buffer, &pop)));
  printf("%s\n", pop);
  if (len > 0)
    free(pop);
  free(pushedText);
  printf("read %d bytes on stdin\n", ring_buf_read(buffer, 0));
  ring_buf_push(buffer, "\n");
  printf("popped a string of length %d\n", (len = ring_buf_pop_alloc(buffer, &pop)));
  printf("%s\n", pop);
  if (len > 0)
    free(pop);
  printf("printed %d bytes on stdout\n", ring_buf_write(buffer, 1));
  pushedText = malloc((RING_BUF_SIZE + 1) * sizeof(char));
  memset(pushedText, 'c', RING_BUF_SIZE);
  pushedText[RING_BUF_SIZE] = '\0';
  ring_buf_push(buffer, pushedText);
  printf("buffer length: %d\n", ring_buf_len(buffer));
  free(pushedText);
  len = ring_buf_pop(buffer, pop);
  if (len > 0)
    free(pop);
  printf("buffer length: %d\n", ring_buf_len(buffer));
  free(buffer);
  return (0);
}
