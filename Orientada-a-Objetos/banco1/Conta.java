package banco1;

public class Conta {

    private double saldo;

    public double getSaldo() {
        return saldo;
    }

    public void depositar(double valor) {
        saldo = saldo + valor;
    }

    public void sacar(double valor) {
        saldo = saldo - valor;
    }

    public Conta(double saldoInicial) {
        saldo = saldoInicial;
    }

}
