void menuInicial();

void limparTela() {
    system("cls");
}
void inicia_tabuleiro(char tabuleiro[3][3]) {
    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                tabuleiro[i][j] = '-';
            }
        }
}
void exibe_tabuleiro(char tabuleiro[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }
}

//1 = x , 2 = O , 0 = velha
int confere_tabuleiro (char tabuleiro[3][3]) {

     ///Linhas
    for (int i = 0; i < 3; i++){
       //Linhas
       if(tabuleiro[i][0] == 'X' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
        return 1;
       } else if (tabuleiro[i][0] == 'O' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]){
        return 2;
       }
    }
    ///Colunas
    for (int i = 0; i < 3; i++){
       //Colunas
       if(tabuleiro[0][i] == 'X' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]){
        return 1;
       } else if (tabuleiro[0][i] == 'O' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]){
        return 2;
       }
    }
    ///Diagonal principal
    if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro [2][2]){
        if(tabuleiro[0][0] == 'X'){
            return 1;
        } else {
            return 2;
        }
    }
    ///Diagonal secundaria
    if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro [2][0]){
        if(tabuleiro[0][2] == 'X'){
            return 1;
        } else {
            return 2;
        }
    }
}

void jogo(){

    ///variaveis gerais
    char tabuleiro[3][3];       //tabuleiro
    string nome1,nome2;
    int linha_jogada, coluna_jogada; //Posicao que o jogador posiciona
    int turno = 1; // 1 = X | 2 = O
    int rodada = 1 ;
    inicia_tabuleiro(tabuleiro);
    int estado_deJogo = 1;

    cout << "\nDigite o nome do primeiro jogador(X): ";
    cin >> nome1;
    cout << "\nDigite o nome do segundo jogador(O): ";
    cin >> nome2;

    while(rodada != 10 && estado_deJogo == 1){
    limparTela();

    exibe_tabuleiro(tabuleiro);
    cout << "\nRodada: " << rodada << "\n";
    if(turno == 1) {
        cout << nome1 << "\n";
        cout << "Digite uma linha: ";
        cin >> linha_jogada;
        cout << "\nDigite uma coluna: ";
        cin >> coluna_jogada;
    } else {
        cout << nome2 << "\n";
        cout << "Digite uma linha: ";
        cin >> linha_jogada;
        cout << "\nDigite uma coluna: ";
        cin >> coluna_jogada;
    }


    if(turno == 1) {
        tabuleiro[linha_jogada][coluna_jogada] = 'X';
        turno ++;
    } else {
        tabuleiro[linha_jogada][coluna_jogada] = 'O';
        turno = 1;
    }

    if(confere_tabuleiro(tabuleiro) == 1) {
       cout << "O jogador " << nome1 <<  " venceu";
        estado_deJogo = 0;
    } else if (confere_tabuleiro(tabuleiro) == 2){
        cout << "O jogador " << nome2 <<  " venceu";
        estado_deJogo = 0;
    }

    rodada++;
    }
    cout << "\n";
    exibe_tabuleiro(tabuleiro);
    cout << "\nfim de jogo\n";
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
