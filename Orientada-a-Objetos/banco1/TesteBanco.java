package banco1;

public class TesteBanco {
    public static void main(String[] args) {
        Conta conta;

        System.out.println("Criando uma conta com saldo de R$ 1.000,00.");
        conta = new Conta(1000.00);

        System.out.println("Sacando R$ 250,00");
        conta.sacar(250.00);

        System.out.println("Depositando R$ 320,50");
        conta.depositar(320.50);

        System.out.println("Sacando R$ 120");
        conta.sacar(120.00);

        System.out.println("O saldo da conta é R$ " + conta.getSaldo());
    }
}
