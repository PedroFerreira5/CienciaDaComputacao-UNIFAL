package banco8;

public class ContaCorrente extends Conta{
    private Conta contaPoupanca;

    public ContaCorrente(double saldoInicial, ContaPoupanca contaPoupanca) {
        super(saldoInicial);
        this.contaPoupanca = contaPoupanca;
    }

    public ContaCorrente(double saldoInicial) {
        super(saldoInicial);
    }

    public boolean sacar(double valor) {

        //  Saldo em conta corrente SUFICIENTE para o saque
        if (valor <= this.saldo) {
            this.saldo -= valor;
            return true;
        }

        //  Saldo em conta corrente + saldo em conta poupança SUFICIENTES para o saque
        if ((contaPoupanca != null) && (this.saldo + this.contaPoupanca.getSaldo()) >= valor) {
            double valorDebitadoPoupanca = valor - this.saldo;
            this.saldo = 0.0;
            this.contaPoupanca.sacar(valorDebitadoPoupanca);
            return true;
        } else { //  Saldo em conta corrente + saldo em conta poupança INSUFICIENTES para o saque
            return false;
        }
    }

    public Conta getContaPoupanca() {
        return contaPoupanca;
    }

    public void setContaPoupanca(Conta contaPoupanca) {
        this.contaPoupanca = contaPoupanca;
    }
}
