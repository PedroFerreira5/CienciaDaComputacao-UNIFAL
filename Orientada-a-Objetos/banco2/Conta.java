package banco2;

public class Conta {

    private double saldo;

    public Conta(double saldoInicial) {
        saldo = saldoInicial;
    }

    public double getSaldo() {
        return saldo;
    }

    public void depositar(double valor) {
        this.saldo = saldo + valor;
    }

    public void sacar(double valor) {
        saldo = saldo - valor;
    }

}
