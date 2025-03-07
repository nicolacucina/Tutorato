public class Rettangolo {
	private int base;
	private int altezza;
	private int ascissa;
	private int ordinata;

	/* costruttore: permette di creare un rettangolo specificando base, altezza e coordinate del punto in alto a sinistra*/
	public Rettangolo(int b, int h, int x, int y) {
		base = b;
		altezza = h;
		ascissa = x;
		ordinata = y;
	}

	/* restituisce la base del rettangolo */
	public int getBase() {
		return base;
	}

	/* restituisce l'altezza del rettangolo */
	public int getAltezza() {
		return altezza;
	}

	/* restituisce l'ascissa del rettangolo */
	public int getAscissa() {
		return ascissa;
	}

	/* restituisce l'ordinata del rettangolo */
	public int getOrdinata() {
		return ordinata;
	}

	/* modifica la base del rettangolo */
	public void setBase(int nuovaBase) {
		base = nuovaBase;
	}

	/* modifica l'altezza del rettangolo */
	public void setAltezza(int nuovaAltezza) {
		altezza = nuovaAltezza;
	}

	/* trasla il rettangolo modificando l'ascissa e l'ordinata del suo punto in alto a sinistra */
	public void traslazione(int trX, int trY) {
		ascissa = ascissa + trX;
		ordinata = ordinata + trY;
	}

	/* restituisce il perimetro del rettangolo */
	public int getPerimetro() {
		return (base + altezza)*2;
	}

	/* restituisce l'area del rettangolo */
	public int getArea() {
		return base * altezza;
	}

	/* stampa il rettangolo */
	public String toString() {
		String s = "";
		for (int i=0; i<ordinata; i++) {
			for (int j=0; j<ascissa+base; j++) {
				s+=" ";
			}
			s+="\n";
		}
		for (int i=0; i<ascissa; i++) {
			s+=" ";
		}
		for (int i=ascissa; i<ascissa+base; i++) {
			s+="o";
		}
		s+="\n";
		for (int j=0; j<ordinata+altezza-2; j++){
			for (int i=0; i<ascissa; i++) {
				s+=" ";
			}
			s+="o";
			for (int i=ascissa; i<ascissa+base-2; i++) {
				s+=" ";
			}
			s+="o";
			s+="\n";
		}
		for (int i=0; i<ascissa; i++) {
			s+=" ";
		}
		for (int i=ascissa; i<ascissa+base; i++) {
			s+="o";
		}
		return s;
	}
}