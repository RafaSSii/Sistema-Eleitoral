# Sistema de Votação 🗳️

Este sistema permite gerenciar eleitores com base em seus títulos de eleitor utilizando uma Árvore Binária de Busca (BST).

Características do Programa 🦾

Código desenvolvido em linguagem C; 🖥️
A estrutura de dados escolhida Árvore Binária de Busca (BST). 🔗

O programa é acessado através do terminal; ⌨️

Ele tem CRUD 📊

Os dados sejam mantidos em um arquivo de texto chamado banco_dados.txt; 💾

  ---
  
  Estrutura de Dados Utilizada
O projeto utiliza a seguinte estrutura para representar os contatos:

![image](https://github.com/user-attachments/assets/5a982729-47f3-45a4-84ea-2786e62428b4)

Cada base de eleitor armazena o nome, titulo de eleitor e o voto, utilizando os nós esquerdo e direito da árvore.

![image](https://github.com/user-attachments/assets/00e48dc2-ca6a-4dbb-8ee9-40dd35c4de14)


---
# Menu Principal do Programa
O programa é controlado por um menu interativo via terminal, com as seguintes opções:

![image](https://github.com/user-attachments/assets/163f3e7e-d62e-4ae3-b3d8-676f2af50939)

1. Cadastra um eleitor
   
   ![image](https://github.com/user-attachments/assets/2b6b20c6-bb20-4994-96f6-2074c3a90533)
   
2. Busca e mostra os dados do eleitor através do título
   
   ![image](https://github.com/user-attachments/assets/dee8f442-45c1-460c-991c-93982abcf958)
   
3. Poderá alterar o voto do eleitor
   
   ![image](https://github.com/user-attachments/assets/fee89c1f-3122-431b-a05f-e6e565c4886f)
   
4. Pode apagar um eleitor
   
   ![image](https://github.com/user-attachments/assets/f8ed9a98-a920-4c8f-8126-921766b66965)
   
5. Mostra os eleitores, seu título e seu voto
    
   ![image](https://github.com/user-attachments/assets/ed859961-17ee-4576-abf6-c1990f686acc)
   

O arquivo database.txt é utilizado para armazenar os contatos registrados

---

Para compilar o projeto, utilize o seguinte comando no terminal:

`gcc votacao.c -o votacao`

Para executar o programa após a compilação:

`./votacao`





