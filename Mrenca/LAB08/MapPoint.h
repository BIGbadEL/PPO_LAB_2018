#pragma once

/**
 * @class MapPoint
 * @brief klasa przechowująca punkt na mapie
*/

class MapPoint{
    public:

        /**
         * @MapPoint
         * @brief konstruktor klasy MapPoint
        */

      constexpr MapPoint(double lat, double log): _lat(lat), _log(log) {    }

      /**
       * @fn print
       * @breif wypisuje punkt na ekran
      */

      void print() const;

      /**
       * @fn move 
       * @brief przesuwa punkt o zadane wartości
       * @param x -> double wartośc do przesuniecia szerokości geograficznej
       * @param y -> double wartosc do przesuniecia długości geograficznej
      */

      void move(double x, double y);

      /**
       * @fn furthrFrom
       * @breief zwraca punkt bliższy do obiektu
       * @param x -> punkt na mapie
       * @param y -> punkt na mapie
       * @return punkt bliższy do obiektu na którm została wywołana
      */

      inline const MapPoint& furtherFrom( const MapPoint& x, const MapPoint& y) const{ return (length(x) > length(y)) ? x : y;}

      /**
       * @fn length
       * @brief oblicza odległość między zadanym punketm a obiketm na któym został wywołany
       * @param from -> punkt do którego odległość chcemy obliczć
       * @return [double] odległość do kwadratu
      */

      constexpr inline double length(const MapPoint& from) const{ return (_lat - from._lat) * (_lat - from._lat) + (_log - from._log) * (_log - from._log);}

      /**
       * @fn inTheMidle 
       * @brief oblicza punkt pomiędzy zadnami punktami
       * @param x -> punkt na mapie
       * @param y -> punkt na mapie
       * @reutrn Punkt pomiędzy dwoma zadanimi
      */

      static MapPoint inTheMiddle(const MapPoint& x,  const MapPoint& y);

    private:
        double _lat;
        double _log;
};