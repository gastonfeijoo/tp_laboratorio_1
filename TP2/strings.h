/** \brief Devuelve una cadena, no le permite al usuario ingresar mas caracteres del largo definido
 *
 * \param string char* el array de la cadena a obtener
 * \param sizeString int tamaño del array, usar sizeOf()
 * \return void
 *
 */
void GetString(char *string, int sizeString);
int GetNumberInteger();
float GetNumberFloat();

int InputCursorBackspace(int i);
int InputCursorValidCharacter (char * string,int i, char aux);
int InputCursorLimit (int i);
