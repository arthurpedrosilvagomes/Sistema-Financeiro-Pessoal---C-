/*

Instituição: UNIMA | Afya
Curso: Ciência da Computação
Periodo: 1º

Área: finanças e economia
Tema: Sistema financeiro pessoal

Integrantes:
    Arthur Pedro
    Matheus Marinho
    Murilo Mendes
    Kauã Macena
    João Kennedy

Sobre:
Projeto orientado pelo professor Francisco Vital da disciplina de
Algorítimo e Programação. Data da apresentação do projeto é no dia 13/04
Pontuação referente ao roterio de atividades N1

*/

//bibliotecas utilizadas no aplicativo
#include <iostream> // gerenciador de entrada e saida de valores
#include <vector> // gerenciador de vetores

// estrutura que representa a transação
struct Transacao {

    // Variaveis que são consideradas nomes
    std::string descricao, categoria, data;

    // Variavel que é considerada booleana
    bool entrada; // 'true' para receita, 'false' para despesa

    // Variavel que é numero
    float valor;
};

// Classe que representa a conta do usuário
class Conta {
protected:

    // Lista de transações
    std::vector<Transacao> transacoes;

public:

    // Método que adiciona uma transação á lista de transações
    void adicionar_transacao() {

        // Variavel que armazena a estrutura transacao e seus valores
        Transacao transacao;

        // Variaves que são consideradas nomes. Essas vão receber valores de entrada do usuário
        std::string descricao, categoria, data;

        // Entrada de valor do usuário para a variavel descricao
        std::cout << "Informe a descrição dessa transação: ";
        std::cin >> descricao;
        transacao.descricao = descricao;

        // Entrada de valor do usuário para a variável categoria
        std::cout << "Informe a categoria dessa transação: ";
        std::cin >> categoria;
        transacao.categoria = categoria;

        // Entrada de valor do usuário para a variável categoria
        std::cout << "Informe a data dessa transação: ";
        std::cin >> data;
        transacao.data = data;

        // Variavel que irá definir se a entrada é uma receita ou despesa;
        int entrada;

        // Loop que analisa o valor de 'entrada' enquanto ela não recebe valor
        while (entrada != 1 && entrada != 2) {

            // Opções que são exibidas para o usuário
            std::cout << "Informe a entrada dessa transação: " << std::endl
                      << "[1] Receita" << std::endl
                      << "[2] Despesa" << std::endl
                      << ">>> ";

            // Entrada de valor para a variavel entrada
            std::cin >> entrada;

            // Se o valor recebido for 1
            if (entrada == 1) {

                // definir o valor entrada da transacao como true
                transacao.entrada = true;
            }

            // Se o valor recebido for 2
            else if (entrada == 2) {

                // definir o valor entrada da transacao como false
                transacao.entrada = false;
            }

            // Se o valor recebido não for nenhum dos dois esperados
            else {

                // Mensagem de instrução
                std::cout << "Insira apenas os valores que foram exibidos" << std::endl;
            }
        }
        
        // Variavel considerado número que irá receber valor de entrada do usuário
        float valor;
        std::cout << "Insira o valor da transação: ";
        std::cin >> valor;
        transacao.valor = valor;

        // Mensagem anunciando o sucesso ao adicionar uma nova transação
        std::cout << "transação adicionada com sucesso" << "\n" << std::endl;

        // Adicionando transacao á lista transacoes
        transacoes.push_back(transacao);
    }

    // Mostra as transações que estão na lista
    void mostrar_transacoes() {

        // Condicional que analisa se há transações na lista
        if (transacoes.size() == 0) {

            // Mensagem que alerta sobre a ausencia de transações
            std::cout << "Você não tem transações ainda" << std::endl;
        }

        // Caso haja transações na lista
        else {

            // Repetição que analisa as transações que estão na lista
            for (const auto& t: transacoes) {

            // Condicional que analisa a entrada da transação
            if (t.entrada) {

                // Exibirá Receita se o valor da variavel entrada for true
                std::cout << "=== Receita ===" << std::endl;
            } else {

                // Exibirá Despesa se o valor da variavel entrada for false
                std::cout << "=== Despesa ===" << std::endl;
            }

            // Exibir descrição
            std::cout << "Descrição: " << t.descricao << std::endl;

            // Exibir categoria
            std::cout << "Categoria: " << t.categoria << std::endl;

            // Exibir data
            std::cout << "Data: " << t.data << std::endl;

            // Exibir valor
            std::cout << "Valor " << t.valor << "(TRABALHO EM ANDAMENTO)\n" << std::endl;
            }
        }
    }

    // Método para calcular o saldo baseado nas transações da conta
    void calcular_saldo() {

        // Valor do saldo caso não tenha nenhuma transação
        float saldo = 0;

        // Repetição que passa por cada transação
        for (const auto& t: transacoes) {

            // Condicional que analisa o tipo de entrada da transação
            if (t.entrada == true) {

                // Adiciona o valor da transação ao saldo
                saldo += t.valor;
            
            // Bloco que analisa a situação contrária
            } else {

                // Subtrai o valor da transação do saldo
                saldo -= t.valor;
            }
        }

        // Demonstra o valor do saldo após analisar as transações
        std::cout << "Saldo aproximado: " << saldo << "\n" << std::endl;
    }

    // Método para eliminar uma transação na lista transacoes
    void eliminar_transacao() {
        
    }
};

// Bloco onde tudo vai ser executado
int main() {

    // Variavel que guarda o valor de entrada do usuário
    int escolha_do_usuario;

    // Variavel que armazena a classe Conta
    Conta conta;

    // Interface do usuário
    while (escolha_do_usuario != 0) {
        std::cout << "=== Sistema Financeiro Pessoal ===" << std::endl
                  << "[1] Adicionar transação" << std::endl
                  << "[2] Listar transações" << std::endl
                  << "[3] Visualisar saldo" << std::endl
                  << "[4] Excluir transação" << std::endl
                  << "[0] Sair" << std::endl
                  << ">>> ";
        std::cin >> escolha_do_usuario;

        // Condicionais que fazem uma execução de acordo com o valor da variavel escolha_do_usuario
        switch (escolha_do_usuario) {

            // Adiciona uma transação
            case 1:

                // Método adicionar_transacao da classe Conta sendo chamado na variavel conta
                conta.adicionar_transacao();
                break;
            
            // Mostra todas as transações feitas
            case 2:
                
                // Método mostrar_transacoes da classe Conta sendo chamado na variavel conta
                conta.mostrar_transacoes();
                break;
            
            // Visualiza o saldo de acordo com as transações feitas
            case 3:
                
                // Método calcular_saldo da classe Conta sendo chamado na variavel conta
                conta.calcular_saldo();
                break;
            
            // Remove uma transação da lista de transações
            case 4:
                break;
            
            // Exceção para todo valor que não foi apresentado
            default:

                // Mensagem de instrução
                std::cout << "selecione apenas os valores exibidos" << std::endl;
        }
    }
    
    // finalização da execução do aplicativo
    return 0;
}