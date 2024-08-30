# Minitalk

## Visão Geral

Minitalk é um programa de troca de dados que utiliza sinais UNIX para a comunicação entre um cliente e um servidor. O objetivo deste projeto é demonstrar a comunicação entre processos em C usando apenas os sinais SIGUSR1 e SIGUSR2.

## Funcionalidades

- **Comunicação cliente-servidor**: O cliente envia uma string para o servidor, que a recebe e exibe;
- **Manipulação de sinais**: A comunicação é feita exclusivamente usando sinais UNIX;

- **Bônus**:
  - O servidor reconhece cada mensagem recebida enviando um sinal de um sinal de volta para o cliente.
  - Suporte a caracteres Unicode.

### Instalação

1. Clone o repositório:
   ```bash
   git clone <url_do_repositorio>
   cd minitalk

2. Compile o projeto:
   ```bash
   make ou make bonus

### Uso
   
1. Inicie o servidor:
   ```bash
   ./server
   
2. Execute o cliente com o PID do servidor e a mensagem que você deseja enviar:
   ```bash
   ./client <pid_servidor> "<mensagem>"

   
