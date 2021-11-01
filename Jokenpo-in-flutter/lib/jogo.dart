import 'dart:math';
import 'package:flutter/material.dart';

class Jogo extends StatefulWidget {
  @override
  _JogoState createState() => _JogoState();
}

class _JogoState extends State<Jogo> {
  var _imagemApp = AssetImage("imagens/padrao.png");

  var _messagem = "Escolha uma opção abaixo";
  void _opcaoSelecionada(String escolhaUsuario){
    var opcao = [
      "pedra",
      "papel",
      "tesoura",
    ];
    var numero = Random().nextInt(opcao.length);
    var escolhaApp = opcao[numero];
    switch (escolhaApp){
      case "pedra":
      setState(() {
        this._imagemApp = AssetImage("imagens/pedra.png");
      });
      break;
      case "papel":
        setState(() {
          this._imagemApp = AssetImage("imagens/papel.png");
        });
        break;
      case "tesoura":
        setState(() {
          this._imagemApp = AssetImage("imagens/papel.png");
        });
        break;
    }

    if(escolhaUsuario == "pedra" && escolhaApp == "tesoura" ||
        escolhaUsuario == "tesoura" && escolhaApp == "papel" ||
        escolhaUsuario == "papel" && escolhaApp == "pedra"){
      setState(() {
        this._messagem = "Parabéns, você venceu!";
      });
    }
    else if(escolhaApp == "pedra" && escolhaUsuario == "tesoura" ||
        escolhaApp == "tesoura" && escolhaUsuario == "papel" ||
        escolhaApp == "papel" && escolhaUsuario == "pedra"){
      setState(() {
        this._messagem = "Você Perdeu!";
      });
    }
    else{
      setState(() {
        this._messagem = "Empatou!";
      });
    }
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Jokenpo"),
      ) ,
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.center,
        children: <Widget>[
          Padding(
            padding: const EdgeInsets.only(top: 32, bottom: 16),
            child: Text(
              "Escolha do App",
              style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),
              textAlign: TextAlign.center,
            ),
          ),
          GestureDetector(
            onTap: (){
              print("Clicado");
            },
            child: Image(
              image: _imagemApp,
            ),
          ),

          Padding(
            padding: const EdgeInsets.only(top: 32, bottom: 16),
            child: Text(_messagem,
              style: TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),
              textAlign: TextAlign.center,
            ),
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: <Widget>[
              GestureDetector(
                onTap: () => _opcaoSelecionada,
                child: Image.asset("imagens/pedra.png", width: 100,),
              ),
              GestureDetector(
                onTap: () => _opcaoSelecionada,
                child: Image.asset("imagens/papel.png", width: 100,),
              ),
              GestureDetector(
                onTap: () => _opcaoSelecionada,
                child: Image.asset("imagens/tesoura.png", width: 100,),
              ),
            ],
          )
        ],
      ),
    );
  }
}
