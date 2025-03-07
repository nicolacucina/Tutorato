package classi;

public class ContoCorrente {
	private double saldo;
	private String password;

	/* costruttore: permette di creare un conto corrente bancario con saldo uguale a zero e registrare una password */
	public ContoCorrente(String p){
		this.saldo = 0.0;
		this.password = p;
	}

	/* effettua un versamento */
	public String deposita(double d, String p) {
		String res_deposito = "Password errata!";
		if (this.controlloPassword(p)){
			saldo += d;
			return res_deposito = "Deposito effettuato con successo!";
		}
		return res_deposito;
	}

	/* effettua un prelievo */
	public String preleva(double d, String p) {
		String res_prelievo = "Password errata!";
		if (this.controlloPassword(p)){
			saldo -= d;
			return res_prelievo = "Prelievo effettuato con successo!";
		}
		return res_prelievo;
	}

	/* restituisce il saldo */
	public double leggiSaldo() {
		return saldo;
	}

	/* aggiunge l'interesse al conto */
	public void aggiungiInteresse(double interesse) {
		if (saldo>0)
			saldo += (saldo*interesse)/100;
 	}

	public boolean controlloPassword(String p){
		if (p.equals(password))
			return true;
		else return false;
	}
}