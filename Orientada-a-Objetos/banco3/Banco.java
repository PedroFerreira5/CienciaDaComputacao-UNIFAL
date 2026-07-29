package banco3;

public class Banco {
    private Cliente[] clientes;
    private int numeroClientes;

    public Banco() {
        this.clientes = new Cliente[5];
    }

    public void adicionarCliente(Cliente cliente) {
        clientes[numeroClientes] = cliente;
        numeroClientes++;
    }

    public Cliente getCliente(int indice) {
        return clientes[indice];
    }

    public int getNumeroDeClientes() {
        return this.numeroClientes;
    }
}
