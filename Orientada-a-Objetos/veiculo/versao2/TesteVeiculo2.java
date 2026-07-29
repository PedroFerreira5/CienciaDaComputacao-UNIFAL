package veiculo.versao2;

public class TesteVeiculo2 {
  public static void main(String[] args) {

    // Cria um veiculo que suporta a carga de 10.000 kg
    System.out.println("Criando um veículo com carga máxima de 10.000kg");
    Veiculo veiculo = new Veiculo(10000.0);

    // Adicionando algumas caixas
    System.out.println("Adicionando caixa número 1 (500kg) : " + veiculo.adicionarCaixa(500.0));
    System.out.println("Adicionando caixa número 2 (250kg) : " + veiculo.adicionarCaixa(250.0));
    System.out.println("Adicionando caixa número 3 (5000kg) : " + veiculo.adicionarCaixa(5000.0));
    System.out.println("Adicionando caixa número 4 (4000kg) : " + veiculo.adicionarCaixa(4000.0));
    System.out.println("Adicionando caixa número 5 (300kg) : " + veiculo.adicionarCaixa(300.0));

    // Exibindo a carga total do veículo
    System.out.println("A carga do veiculo é: " + veiculo.getCarga() + " kg");

  }
}
