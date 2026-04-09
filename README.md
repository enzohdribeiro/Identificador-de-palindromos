# Identificador de Palíndromos

Atividade proposta pelo professor Luciano A. Digiampietri em Introdução à Programação.

Programa em C que verifica se uma string fornecida pelo usuário é um palíndromo (lê-se igual de trás para frente, desconsiderando diferenças entre maiúsculas e minúsculas, exemplo: ovo;osso)

## Funcionalidades

- Leitura dinâmica da entrada do usuário sem limite pré-definido de caracteres
- Alocação de memória flexível que se adapta ao tamanho da string fornecida
- Verificação eficiente comparando apenas metade dos caracteres
- Loop contínuo permitindo múltiplas verificações e saída do programa quando solicitado

## Principais componentes

### Alocação Dinâmica (função `criaTexto`)

- Inicia com buffer de 5 caracteres
- Expande automaticamente a capacidade dobrando o tamanho sempre que necessário
- Realoca memória suficiente para o tamanho exato da input no final, não desperdiçando memória
- Suporta entrada até o limite de memória disponível

### Contagem de caracteres (função `contagem`)

- Percorre a string até encontrar o terminador nulo '\0'
- Retorna o número exato de caracteres

### Verificação de palíndromo (função `palindromo`)

- Compara o primeiro com o último caractere, o segundo com o penúltimo, e assim sucessivamente
- Realiza apenas n/2 comparações, onde n é o tamanho da string
- Retorna 1 para palíndromo e 0 para não palíndromo

  ### Gerenciamento de memória

- Liberação da memória alocada a cada iteração com `free(texto)`
- Previne vazamento de memória durante execução prolongada
