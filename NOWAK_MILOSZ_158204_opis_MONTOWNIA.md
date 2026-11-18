# Projekt Systemy Operacyjne 2026/2027 – Temat 18: Montownia

* **Autor:** Miłosz Nowak
* **Nr albumu:** 158204
* **Grupa laboratoryjna:** 4
* **Repozytorium GitHub:** https://github.com/Miloszxx/SO-Montownia-2026

---

## Opis projektu

W hali produkcyjnej znajdują się: magazyn na podzespoły, dwa stanowiska montażowe (`S1` i `S2`) oraz taśma transportująca gotowe produkty na rampę, z której ciężarówki rozwożą je do odbiorców.

### Zasoby i parametry symulacji
* **Magazyn:** pojemność $P$ jednostek magazynowych. Przechowuje 4 typy podzespołów dostarczanych przez 4 niezależne procesy dostawców w losowych momentach (fabryka przyjmuje maksymalnie dużo podzespołów, na ile pozwala wolne miejsce):
  * `P1` – zajmuje 1 jednostkę,
  * `P2` – zajmuje 2 jednostki,
  * `P3` – zajmuje 3 jednostki,
  * `P4` – zajmuje 3 jednostki.
* **Stanowiska montażowe:**
  * `S1` – składa wyrób z podzespołów `P1 + P2 + P3` (łączna masa produktu: 6 jednostek),
  * `S2` – składa wyrób z podzespołów `P2 + P3 + P4` (łączna masa produktu: 8 jednostek).
* **Taśma transportowa:**
  * Jednocześnie mieści maksymalnie $K$ sztuk produktów,
  * Maksymalny udźwig taśmy wynosi $M$ jednostek masy, przy czym $8K > M$ (na taśmę nie można położyć jednocześnie $K$ najcięższych produktów ze stanowiska `S2`),
  * Produkty zjeżdżają z taśmy na ciężarówkę w ścisłej kolejności FIFO (zgodnie z kolejnością położenia na taśmie).
* **Flota ciężarówek:**
  * Łącznie $N$ ciężarówek, każda o ładowności $L$ jednostek,
  * Ciężarówka przy rampie musi zostać załadowana do pełna (chyba że dyrektor wyda odpowiednie polecenie), po czym odjeżdża i wraca po losowym czasie $T_i$. Na jej miejsce natychmiast podstawiana jest kolejna wolna ciężarówka (jeśli jest dostępna).

### Procesy w systemie
1. **Dyrektor** – zarządza przebiegiem symulacji i wysyła sygnały sterujące (`polecenie_1` – `polecenie_5`).
2. **Dostawca** (4 procesy) – dostarczają podzespoły `P1`–`P4` do magazynu.
3. **Pracownik montażowy** (stanowiska `S1` i `S2`) – pobiera podzespoły z magazynu, montuje wyroby i odkłada je na taśmę najszybciej, jak to możliwe.
4. **Kierowca ciężarówki** ($N$ procesów) – odbiera produkty z końca taśmy, realizuje kurs po zapełnieniu pojazdu i wraca na rampę.

### Obsługa poleceń (sygnałów) Dyrektora
* `polecenie_1` – magazyn kończy pracę (wstrzymanie przyjmowania nowych dostaw).
* `polecenie_2` – montownia kończy pracę.
* `polecenie_3` – montownia i magazyn kończą pracę jednocześnie; aktualny stan magazynu zapisywany jest do pliku, a po ponownym uruchomieniu symulacji stan ten jest z pliku odtwarzany.
* `polecenie_4` – ciężarówka stojąca aktualnie przy taśmie odjeżdża z niepełnym ładunkiem.
* `polecenie_5` – pracownicy na wskazanym stanowisku (`S1` lub `S2`) kończą pracę.
* Po rozwiezieniu wszystkich wyprodukowanych produktów ciężarówki kończą pracę, a przebieg symulacji zapisywany jest w pliku tekstowym (logach).