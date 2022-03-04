void menuInicial();

void limparTela() {
    system("cls");
}

void exibe_tabuleiro(char tabuleiro[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = '-';
            cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }

}
void jogo(){

    ///variaveis gerais
    char tabuleiro[3][3];       //tabuleiro
    exibe_tabuleiro(tabuleiro);

}


void menuInicial() {
    int opcao = 0;
    while (opcao < 1 || opcao > 3) {
        limparTela();
        cout << "Bem vindo ao jogo da forca!\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sobre\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opção: ";

        cin >> opcao;

        switch (opcao) {
        case 1:
            limparTela();
            cout << "Jogo iniciado! \n";
            jogo();
            break;
        case 2:
            limparTela();
            cout << "Sobre o jogo: \n";
            break;
        case 3:
            limparTela();
            cout << "Saindo... \n";
            break;
        }
    }
}
