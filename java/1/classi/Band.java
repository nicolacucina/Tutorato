public class Band {
	private String nome;
	private Musicista cantante;
	private Musicista batterista;
	private Musicista tastierista;
	private Musicista chitarrista;
	private Musicista bassista;

	/* costruttore: permette di creare una band specificando il suo nome e i suoi 5 componenti */
	public Band(String n, Musicista m1, Musicista m2, Musicista m3, Musicista m4, Musicista m5){
		this.nome = n;
		switch(m1.getStrumento()) {
			case "voce":
				this.cantante = m1;
				break;
			case "batteria":
				this.batterista = m1;
				break;
			case "tastiera":
				this.tastierista = m1;
				break;
			case "chitarra":
				this.chitarrista = m1;
				break;
			case "basso":
				this.bassista = m1;
				break;
		}
		switch(m2.getStrumento()) {
			case "voce":
				this.cantante = m2;
				break;
			case "batteria":
				this.batterista = m2;
				break;
			case "tastiera":
				this.tastierista = m2;
				break;
			case "chitarra":
				this.chitarrista = m2;
				break;
			case "basso":
				this.bassista = m2;
				break;
		}
		switch(m3.getStrumento()) {
			case "voce":
				this.cantante = m3;
				break;
			case "batteria":
				this.batterista = m3;
				break;
			case "tastiera":
				this.tastierista = m3;
				break;
			case "chitarra":
				this.chitarrista = m3;
				break;
			case "basso":
				this.bassista = m3;
				break;
		}
		switch(m4.getStrumento()) {
			case "voce":
				this.cantante = m4;
				break;
			case "batteria":
				this.batterista = m4;
				break;
			case "tastiera":
				this.tastierista = m4;
				break;
			case "chitarra":
				this.chitarrista = m4;
				break;
			case "basso":
				this.bassista = m4;
				break;
		}
		switch(m5.getStrumento()) {
			case "voce":
				this.cantante = m5;
				break;
			case "batteria":
				this.batterista = m5;
				break;
			case "tastiera":
				this.tastierista = m5;
				break;
			case "chitarra":
				this.chitarrista = m5;
				break;
			case "basso":
				this.bassista = m5;
				break;
		}
	}

	/* modifica il nome della band */
	public void setNome(String n){
		this.nome = n;
	}

	/* modifica un componente della band, a seconda dello strumento di m */
	public void setMusicista(Musicista m){
		switch(m.getStrumento()) {
			case "voce":
				this.cantante = m;
				break;
			case "batteria":
				this.batterista = m;
				break;
			case "tastiera":
				this.tastierista = m;
			break;
			case "chitarra":
				this.chitarrista = m;
			break;
			case "basso":
				this.bassista = m;
			break;
		}
	}

	/* stampa la descrizione della band */
	public String stampaDescrizione() {
		String d = "NOME DELLA BAND\n"+this.nome+"\nCOMPONENTI\nVoce: "+this.cantante.getNome()+"\nBatteria: "+this.batterista.getNome()+"\nTastiera: "+this.tastierista.getNome()+"\nBasso: "+this.bassista.getNome()+"\nChitarra: "+this.chitarrista.getNome()+"\n";
		return d;
	}
}
