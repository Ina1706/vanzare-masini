#include < iostream >
using namespace std;

//clasa de baza
class masina {
  protected:
    float lungime;
  float pret;
  public:
    masina() {
      lungime = 0;
      pret = 0;
    };
  masina(float l, float m = 0) {
    lungime = l;
    pret = m;
  };
  masina(const masina & a) {
    lungime = a.lungime;
    pret = a.pret;
  };
  ~masina() {
    lungime = 0;
    pret = 0;
  };
  friend istream & operator >> (istream & i, masina & a) {
    cout << "lungime: ";
    i >> a.lungime;
    cout << "pret: ";
    i >> a.pret;
    return i;
  };
  friend ostream & operator << (ostream & o,
    const masina & a) {
    o << "lungime: " << a.lungime << "; pret:" << a.pret << endl;
    return o;
  };
  masina & operator = (const masina & b) {
    lungime = b.lungime;
    pret = b.pret;
    return *this;
  };
  virtual void afisare() {
    cout << * this;
  };
  virtual void citire() {
    cin >> * this;
  };
};

//clasa derivata
class mini: public masina {
  public: mini() {};
  mini(float l, float m = 0) {
    lungime = l;
    pret = m;
  };
  mini & operator = (const mini & );
  friend ostream & operator << (ostream & o,
    const mini & a) {
    masina * b = (masina * ) & a;
    o << * b;
    return o;
  };
  friend istream & operator >> (istream & i, mini & a) {
    if (a.pret == 0) {
      cout << "pret: ";
      cin >> a.pret;
    }
    return i;
  };
  void afisare() {
    cout << * this;
  };
  void citire() {
    cin >> * this;
  };
};

//supraincarcare =
mini & mini::operator = (const mini & b) {
  masina * c = (masina * ) & b;
  masina a = * c;
  masina * d = & a;
  mini * tem = dynamic_cast < mini * > (d);
  return *tem;
}

//clasa derivata
class mica: public masina {
  public: mica() {};
  mica(float l, float m = 0) {
    lungime = l;
    pret = m;
  };
  mica & operator = (const mica & );
  friend ostream & operator << (ostream & o,
    const mica & a) {
    masina * b = (masina * ) & a;
    o << * b;
    return o;
  };
  friend istream & operator >> (istream & i, mica & a) {
    if (a.pret == 0) cout << "pret: ";
    i >> a.pret;
    return i;
  };
  void afisare() {
    cout << * this;
  };
  void citire() {
    cin >> * this;
  };
};

//supraincarcare =
mica & mica::operator = (const mica & b) {
  masina * c = (masina * ) & b;
  masina a = * c;
  masina * d = & a;
  mica * tem = dynamic_cast < mica * > (d);
  return *tem;
}

//clasa derivata
class compacta: public masina {
  char tip;
  public:
    compacta() {};
  compacta(float l, float m = 0) {
    lungime = l;
    pret = m;
  };
  compacta(float l, char t, float m = 0) {
    lungime = l;
    tip = t;
    pret = m;
  };
  compacta & operator = (const compacta & );
  friend ostream & operator << (ostream & o,
    const compacta & a);
  friend istream & operator >> (istream & i, compacta & a);
  void afisare() {
    cout << * this;
  };
  void citire() {
    cin >> * this;
  };
};

//supraincarcare <<
ostream & operator << (ostream & o,
  const compacta & a) {
  o << "lungime: " << a.lungime << "; tip: ";
  switch (a.tip) {
  case 's':
    o << "sedan";
    break;
  case 'c':
    o << "combi";
    break;
  case 'h':
    o << "hatchback";
    break;
  }
  cout << "; pret: " << a.pret << endl;
  return o;
}

//supraincarcare =
compacta & compacta::operator = (const compacta & b) {
  masina * c = (masina * ) & b;
  masina a = * c;
  masina * d = & a;
  compacta * tem = dynamic_cast < compacta * > (d);
  tem - > tip = b.tip;
  tem - > pret = b.pret;
  return *tem;
}

//supraincarcare >>
istream & operator >> (istream & i, compacta & a) {
  int k = 0;
  char t;
  while (k == 0) //verific daca input-ul este corect
  {
    cout << "tip (sedan-s, combi-c, hatchback-h): ";
    cin >> t;
    try {
      if (t != 's' && t != 'c' && t != 'h')
        throw t;
      k = 1;
    } catch (char s) {
      cout << "caracterul " << s << " nu este valid. reincercati" << endl;
    }
  }
  a.tip = t;
  if (a.pret == 0) {
    cout << "pret: ";
    cin >> a.pret;
  }
  return i;
}

//clasa derivata
class monovolume: public masina {
  int nou;
  int fabricatie;
  public:
    monovolume() {};
  monovolume(float l, float m = 0) {
    lungime = l;
    pret = m;
  };
  monovolume(int a, int b, float c = 0, float m = 0) {
    lungime = a;
    nou = b;
    if (nou == 1) {
      fabricatie = 2018;
      return;
    }
    fabricatie = c;
    pret = m;
  };
  monovolume(const monovolume & a) {
    lungime = a.lungime;
    nou = a.nou;
    fabricatie = a.fabricatie;
    pret = a.pret;
  };
  monovolume & operator = (const monovolume & a) {
    lungime = a.lungime;
    nou = a.nou;
    fabricatie = a.fabricatie;
    pret = a.pret;
    return *this;
  };
  friend istream & operator >> (istream & i, monovolume & a);
  friend ostream & operator << (ostream & o, monovolume & a) {
    o << "lungime " << a.lungime << "; an fabr." << a.fabricatie << "; noua: " << a.nou << "; pret: " << a.pret << endl;
    return o;
  };
  void discount();
  void citire() {
    cin >> * this;
  };
  void afisare() {
    cout << * this;
  };
};

//procedura de calcul pentru discount
void monovolume::discount() {
  if (nou == 1)
    return;
  int d = (2018 - fabricatie);
  int k = 0;
  int pls = 0;
  int vara;
  while (k == 0) {
    cout << "e vara? 1-da, 0-nu" << endl;
    cin >> vara;
    try {
      if (vara != 0 && vara != 1) throw vara;
      k = 1;
    } catch (int s) {
      cout << "caracterul " << s << " nu este valid" << endl;
    }
  }
  if (vara == 1)
    pls = 10;
  pret = pret * 0.01 * (100 - d - pls);
}

//supraincarcare >>
istream & operator >> (istream & i, monovolume & b) {
  int k = 0;
  int a;
  while (k == 0) {
    cout << "masina noua? 1-da, 0-nu ";
    cin >> a;
    try {
      if (a != 0 && a != 1)
        throw a;
      k = 1;
    } catch (int s) {
      cout << "caracterul " << s << " nu este valid. reincercati" << endl;
    }
  }
  b.nou = a;
  if (b.nou == 1) {
    b.fabricatie = 2018;
    return i;
  }
  cout << "an fabricatie: ";
  i >> b.fabricatie;
  if (b.pret == 0) {
    cout << "pret: ";
    cin >> b.pret;
  }
  b.discount();
  return i;
}

//citire vector de masini
void hotaraste(int n, masina * v[100]) {
  float l;
  cout << "lungimea masinii: ";
  cin >> l;
  if (l < 3.85) {
    v[n] = new mini(l);
    v[n] - > citire();
    return;
  }
  if (l <= 4.1) {
    v[n] = new mica(l);
    v[n] - > citire();
    return;
  }
  if (l <= 4.5) {
    v[n] = new compacta(l);
    v[n] - > citire();
    return;
  }
  v[n] = new monovolume(l);
  v[n] - > citire();
  return;
}

//afisare vector de masini
void afiseaza(int n, masina * v[100]) {
  for (int i = 0; i < n; i++)
    v[i] - > afisare();
}

//clasa template - vanzare
template < class T >
  class vanzare {
    int stoc;
    int vandut;
    masina * st[100];
    masina * vnd[100];
    public:
      vanzare() {
        stoc = 0, vandut = 0;
      };
    void adauga_stoc(const T & a) {
      st[stoc] = new T(a);
      stoc++;
    };
    vanzare & operator -= (int x) {
      T * temp = dynamic_cast < T * > (st[x]);
      vnd[vandut] = new T( * temp);
      vandut++;
      for (int i = x; i < stoc - 1; i++)
        *
        st[i] = * st[i + 1];
      stoc--;
      return *this;
    }
    void print() {
      cout << "masini in stoc:" << endl;
      for (int i = 0; i < stoc; i++)
        st[i] - > afisare();
      cout << "masini vandute:" << endl;
      for (int i = 0; i < vandut; i++)
        vnd[i] - > afisare();
    }
  };

//specializare pentru int; sunt incarcate numai datele monovolumelor
template < >
  class vanzare < int > {
    int stoc;
    int vandut;
    masina * st[100];
    masina * vnd[100];
    public: vanzare() {
      stoc = 0;
      vandut = 0;
    };
    void adauga_stoc(const monovolume & a) {
      st[stoc] = new monovolume(a);
      stoc++;
    };
    vanzare & operator -= (int x) {
      monovolume * m = dynamic_cast < monovolume * > (st[x]);
      vnd[vandut] = new monovolume( * m);
      vandut++;
      for (int i = x; i < stoc - 1; i++)
        *
        st[i] = * st[i + 1];
      stoc--;
      return *this;
    }

    void print() {
      cout << "masini in stoc" << endl;
      for (int i = 0; i < stoc; i++)
        st[i] - > afisare();
      cout << "masini vandute" << endl;
      for (int i = 0; i < vandut; i++)
        vnd[i] - > afisare();
    }

  };

//meniu vanzari; se cere pozitia din vectorul de masini in stoc atunci cand se vinde o masina
//orice masina vanduta trebuie sa fie oricum in stoc; asa mi s-a parut mai logic
void sales() {
  cout << endl << "VANZARI: " << endl;
  mini m_mini;
  mica m_mica;
  compacta m_compacta;
  monovolume m_monovolume;
  vanzare < mini > v_mini;
  vanzare < mica > v_mica;
  vanzare < compacta > v_compacta;
  vanzare < int > v_monovolume;
  float l = 1;
  int k = 3;
  while (k != 4) {
    cout << "1. adaugare masina" << endl;
    cout << "2. vanzare masina" << endl;
    cout << "3. afisare vectori masini" << endl;
    cout << "4.stop" << endl;
    cin >> k;
    int tip, poz;
    switch (k) {
    case 1:
      cout << "lungimea masinii: ";
      cin >> l;
      if (l < 3.85) {
        mini m_mini(l);
        cin >> m_mini;
        v_mini.adauga_stoc(m_mini);
      } else if (l <= 4.10) {
        mica m_mica(l);
        cin >> m_mica;
        v_mica.adauga_stoc(m_mica);
      } else if (l <= 4.5) {
        compacta m_compacta(l);
        cin >> m_compacta;
        v_compacta.adauga_stoc(m_compacta);
      } else {
        monovolume m_monovolume(l);
        cin >> m_monovolume;
        v_monovolume.adauga_stoc(m_monovolume);
      }
      break;
    case 2:
      cout << "tipul masinii vandute: 1-mini, 2-mica, 3-compacta, 4-monovolume" << endl;
      cin >> tip;
      switch (tip) {
      case 1:
        v_mini.print();
        cout << "pozitia masinii care va fi vanduta?(incepand de la 0)";
        cin >> poz;
        v_mini -= poz;
        break;
      case 2:
        v_mica.print();
        cout << "pozitia masinii care va fi vanduta?(incepand de la 0)";
        cin >> poz;
        v_mica -= poz;
        break;
      case 3:
        v_compacta.print();
        cout << "pozitia masinii care va fi vanduta?(incepand de la 0)";
        cin >> poz;
        v_compacta -= poz;
        break;
      case 4:
        v_monovolume.print();
        cout << "pozitia masinii care va fi vanduta?(incepand de la 0)";
        cin >> poz;
        v_monovolume -= poz;
        break;
      }
      break;
    case 3:
      cout << "MINI" << endl;
      v_mini.print();
      cout << "MICA" << endl;
      v_mica.print();
      cout << "COMPACTA" << endl;
      v_compacta.print();
      cout << "MONOVOLUME" << endl;
      v_monovolume.print();
    }
    cout << "K" << k << endl;
  }
}

int main() {
  cout << "citirea, stocarea si afisarea a n obiecte de tip masina:" << endl;
  masina * v[100];
  int k = 1, p = 0, n = 0;
  while (k != 3) {
    while (p == 0) {
      cout << "1 - adaugare masina" << endl;
      cout << "2 - afisare vector masini" << endl;
      cout << "3 - stop" << endl;
      cin >> k;
      try {
        if (k < 1 && k > 3)
          throw k;
        p = 1;
      } catch (int s) {
        cout << "caracterul " << s << " nu este valid; reincercati" << endl;
      }
    }
    p = 0;
    switch (k) {
    case 1:
      hotaraste(n, v);
      n++;
      break;
    case 2:
      afiseaza(n, v);
      break;
    }
  }

  sales();
}
