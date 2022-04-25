## Trabalho - Agenda 
Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.
Todas as variáveis devem ser ponteiros, a base de dados deve ser implementada com lista encadeada duplamente ligada. Essa lista tem que ser implementada como heap (fila ordenada) em ordem alfabética.

## Estruturas Internas

#### Struct "Imaginária"
 * Struct{       
  char nome[30];  
  int idade;  
  int telefone;  
  void* anterior;  
  void* proximo;  
  }novo_nodo;  
          
  (46 Bytes)
 
 #### pBuffer
 * pBuffer { [0]int aux1, [1]int aux2, [2]int n_nodos, char tempnome[30] }  

 (42 Bytes)

 #### Compilação e Execução
 A compilação pode ser feita normalmente pelo GCC. Em caso de linux, basta retirar o #include windows.h e a primeira linha do main(). 
 
 ### Identificação
 Ulian Gabriel Alff Ramires (ugaramires@inf.ufpel.edu.br)

