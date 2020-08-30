#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

  char* line;
  struct node* next;

} node_t;


int main(int argc, char* argv[])
{

  if(argc > 3){

    fprintf(stderr, "usage: reverse <input> <output>");
    return 1;
  }

  if(argv[1] == argv[2]){

    fprintf(stderr, "Inout and output file must differ");
    return 1;
  }

  char const* const input = argv[1];
  char const* const output= argv[2];

  FILE* inp_read = fopen(input, "r");
  FILE* out_write= fopen(output,"r");

  char* buffer;
  size_t bufsize = 134;
  
  node_t* head;
  node_t* curr;

  buffer = (char*) malloc(bufsize * sizeof(char));
  head = (node_t*) malloc(sizeof(node_t));
  
  curr = head;
  head->next = NULL;

  if(head == NULL ||  buffer == NULL){

    fprintf(stderr,"malloc failed");
    return 1;
  }

  int count = 0;

  while(getline(&buffer, &bufsize, inp_read) && count < 4){

    curr->line = malloc(bufsize * sizeof(char));
    strcpy(curr->line, buffer);

    fwrite(curr->line, 1, 20, stdout);    

    curr->next = (node_t*) malloc(sizeof(node_t));
    curr = curr->next;

    fwrite(head->line, 1, 20, stdout);

    count += 1;
  }

  curr->next = NULL;
  
  return (0);
  
}
