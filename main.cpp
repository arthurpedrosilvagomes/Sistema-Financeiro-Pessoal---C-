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

// bibliotecas utilizadas no aplicativo
#include <iostream>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

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
        std::cout << "Informe a descrição dessa transação (transporte, Alimentação, Salario, Conta, etc): ";
        std::cin >> descricao;
        transacao.descricao = descricao;

        // Entrada de valor do usuário para a variável categoria
        std::cout << "Informe a categoria dessa transação (Fixo ou Variável): ";
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

            switch (entrada) {

                // Receita
                case 1:
                    transacao.entrada = true;
                    break;
                
                // Despesa
                case 2:
                    transacao.entrada = false;
                    break;
                
                // Exceção caso o usuário selecione um numero não exibido
                default:
                    std::cout << "Selecione apenas um dos valores exibidos!" << std::endl;
                    break;
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
            std::cout << "Você não tem transações ainda\n" << std::endl;
        }

        // Caso haja transações na lista
        else {

            // Loop que interage na lista de transações
            for (int i = 0; i < transacoes.size(); i++) {

                // Condicional que analisa a entrada da transação
                if (transacoes[i].entrada == true) {
                    std::cout << i + 1 << ": Receita";
                }

                // Caso o valor da entrada seja false
                else {
                    std::cout << i + 1 << ": Despesa";
                }

                // Resto dos valores das transações serão exibidas
                std::cout << " - " << transacoes[i].categoria
                          << " - " << transacoes[i].descricao
                          << " - " << transacoes[i].data
                          << " - " << transacoes[i].valor << std::endl;
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

        // Exibição das transações
        mostrar_transacoes();

        // Condicional que analisa se existe transações na lista
        if (transacoes.size() != 0) {

            // Variavel que vai guardar a posição da transação a ser eliminada
            int pos_transacao;

            // Entrada de valor do usuário
            std::cout << "Selecione a posição da transação que deseja remover: ";
            std::cin >> pos_transacao;

            // Condicional que analisa a posição da transação
            if (0 < pos_transacao <= transacoes.size()) {
                transacoes.erase(transacoes.begin() + (pos_transacao - 1));
                std::cout << "transacao eliminada com sucesso!\n" << std::endl;
            }

            // Caso ela não exista
            else {
                std::cout << "Não foi possivel eliminar a transação desejada!\n" << std::endl;
            }
        }
    }
};

// Bloco onde tudo vai ser executado
int main() {

    // Correção para a codificação padrão UTF-8. Analise só será feita no windows
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

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
        std::cout << std::endl;

        // Condicionais que fazem uma execução de acordo com o valor da variavel escolha_do_usuario
        switch (escolha_do_usuario) {

            // Adiciona uma transação
            case 1:
                conta.adicionar_transacao();
                break;
            
            // Mostra todas as transações feitas
            case 2:
                conta.mostrar_transacoes();
                break;
            
            // Visualiza o saldo de acordo com as transações feitas
            case 3:
                conta.calcular_saldo();
                break;
            
            // Remove uma transação da lista de transações
            case 4:
                conta.eliminar_transacao();
                break;
            
            // Exceção para todo valor que não foi apresentado
            default:
                std::cout << "selecione apenas os valores exibidos" << std::endl;
        }
    }
    
    return 0;
}