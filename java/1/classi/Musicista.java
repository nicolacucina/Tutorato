public class Musicista {

	private String nome;
	private String strumento;

	/* costruttore: permette di creare un musicista specificando il suo nome e il suo strumento */
	public Musicista(String n, String s){
		this.nome = n;
		this.strumento = s;
	}

	/* restituisce il nome del musicista */
	public String getNome(){
			return nome;
	}

	/* restituisce lo strumento del musicista */
	public String getStrumento(){
		return strumento;
	}
}