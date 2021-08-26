#include <stdio.h>

int main(void)
{
  char buffer[80];

  printf("Digite o texto a ser criptofragado: ");
  scanf("%79[^\n]", buffer);

  char current_char;
  char next_char;

  int i = 0;

  do
  {
    current_char = buffer[i];
    next_char = buffer[i + 1];

    if (current_char == ' ')
    {
      int j = i;
      char ws_removal_swap;

      do
      {
        ws_removal_swap = buffer[j + 1];
        buffer[j + 1] = buffer[j];
        buffer[j] = ws_removal_swap;
        j++;
      } while (ws_removal_swap != '\0');
    }

    i++;
  } while (next_char != '\0');

  i = 0;

  int encryption_key = 1;

  do
  {
    current_char = buffer[i];
    next_char = buffer[i + 1];

    int encrypted_char_code = (int)current_char + encryption_key;

    if (encrypted_char_code > (int)'Z')
    {
      encrypted_char_code = (int)'A' + (encrypted_char_code - (int)'Z' - 1);
    }

    buffer[i] = (char)encrypted_char_code;

    encryption_key++;
    i++;

    if (encryption_key == 6)
    {
      encryption_key = 1;
      printf("RESET\n");
    }

  } while (next_char != '\0');

  printf("%s\n", buffer);

  return 0;
}