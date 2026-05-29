# Sistem de învățare bazat pe jocuri
**Dezvoltarea abilităților prin jocuri interactive**

## Student
**Laura-Maria Rădoi**

Proiectul „Sistem de învățare bazat pe jocuri” reprezintă o aplicație educațională dezvoltată în C++, care îmbină conceptele de programare orientată pe obiecte cu ideea de învățare interactivă prin jocuri.
## Aplicația permite:
- gestionarea utilizatorilor (elevi și profesori),
- rularea unor jocuri educaționale din două categorii principale (Matematică și Geografie),
- evaluarea performanței elevilor,
- oferirea de sugestii de învățare în funcție de scoruri,
- afișarea clasamentelor (leaderboard).

## Structura aplicației

### Categorii de jocuri
Proiectul conține două categorii principale de jocuri:
- Matematică
- Geografie
- Pentru fiecare categorie există trei jocuri, corespunzătoare dificultăților:usor, mediu si greu;
### Utilizator (clasă abstractă)
Clasă de bază pentru toate tipurile de utilizatori.
- **Funcționalități:**
autentificare (login)
metodă virtuală pură getRole() (necesară pentru polimorfism)
### Elev (moștenește Utilizator)
Reprezintă utilizatorul care joacă jocurile educaționale.
### Profesor (moștenește Utilizator)
Reprezintă utilizatorul care administrează jocuri.
### Clasa Joc (clasă de bază)
Reprezintă un joc educațional generic.
- **Funcționalități:**
- metodă virtuală joaca() (implementată diferit în jocurile concrete)
- calcul scor total al jocului
- supraincărcarea operatorului + pentru calcularea scorului total
### Jocuri concrete (moștenesc Joc)
- fiecare joc redefinește metoda joaca()
- întrebările și răspunsurile sunt citite din fișiere text
- scorul este calculat automat în funcție de răspunsurile elevului
- la greșeli, elevul poate primi explicații suplimentare

  ## Concepte de Programare Orientată pe Obiecte utilizate
### Încapsulare
  - atributele claselor sunt protejate/private și accesate prin metode publice
### Moștenire
  - Elev și Profesor moștenesc Utilizator
  - jocurile concrete moștenesc clasa Joc
### Polimorfism
  -  metoda virtuală joaca() este apelată diferit pentru fiecare tip de joc
  -  utilizarea pointerilor la clase de bază (Joc*, Utilizator*)
 ### Clase abstracte și metode virtuale pure:
  - clasa Utilizator conține metoda getRole()
### Supraincărcarea operatorilor:
  - operatorul + supraincărcat în clasa Joc
