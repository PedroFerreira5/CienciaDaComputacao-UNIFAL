package banco6;

public class ContaCorrente extends Conta{
    private double chequeEspecial;

    public ContaCorrente(double saldoInicial, double chequeEspecial) {
        super(saldoInicial);
        this.chequeEspecial = chequeEspecial;
    }

    public ContaCorrente(double saldoInicial) {
        super(saldoInicial);
    }

    public boolean sacar(double valor) {
        // Saldo + valor cheque especial suficientes para cobrir o saque
        if (this.saldo + this.chequeEspecial > valor) {
            this.saldo -= valor;
            return true;
        } else
        return false;
    }
}
