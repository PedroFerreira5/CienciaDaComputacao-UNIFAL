package veiculo.versao1;

public class TesteVeiculo1 {
  public static void main(String[] args) {

    System.out.println("Criando um veículo com carga máxima de 10.000kg.");
    Veiculo veiculo = new Veiculo(10000.0);

    System.out.println("Adicionando Caixa número 1 (500kg)");
    veiculo.carga = veiculo.carga + 500.0;

    System.out.println("Adicionando Caixa número 2 (250kg)");
    veiculo.carga = veiculo.carga + 250.0;

    System.out.println("Adicionando Caixa número 3 (5000kg)");
    veiculo.carga = veiculo.carga + 5000.0;

    System.out.println("Adicionando Caixa número 4 (4000kg)");
    veiculo.carga = veiculo.carga + 4000.0;

    System.out.println("Adicionando Caixa número 5 (300kg)");
    veiculo.carga = veiculo.carga + 300.0;

    System.out.println("A carga do veículo é :" + veiculo.getCarga() + " kg");
  }
}