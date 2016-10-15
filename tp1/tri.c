
void TriInsertion (int* t, int taille){
	int j,i, cle;
	for(j=1; j<taille; j++){
		cle = t[j];
		i = j-1;
		while(i>=0 && t[i]>cle){
			t[i+1] = t[i];
			i--;
		}
		t[i+1] = cle;
	}
}
