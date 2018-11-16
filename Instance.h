
#ifndef NETLIST_INSTANCE_H
#define NETLIST_INSTANCE_H

#include<string>
#include<vector>
#include"Indentation.h"
#include"Point.h"

namespace Netlist {
  class Cell;
  class Term;
  class Net;
    
    class Instance {
        
        private :
        Cell * owner_ ;
        Cell * masterCell_ ;
        std :: string name_ ;
        std :: vector < Term * > terms_ ;
        Point position_ ;
        public :
        void  toXml ( std::ostream& ); //toXml
        Instance ( Cell * owner , Cell * model , const std :: string & );
        ~Instance ();
        inline const std :: string & getName () const ;
        inline Cell * getCell () const ;
        inline const std :: vector < Term * >& getTerms () const ;
        inline Point getPosition () const ;
        inline Cell * getMasterCell () const ;
        Term * getTerm ( const std :: string & ) const ;
        bool connect ( const std :: string & name , Net * );
        void add ( Term * );
        void remove ( Term * );
        void setPosition ( const Point & );
        void setPosition ( int x , int y );
        
    };
    inline const std :: string &           Instance :: getName () const { return name_; }
    inline Cell *                          Instance :: getCell () const { return owner_; }
    inline const std :: vector < Term * >& Instance :: getTerms () const { return terms_; }
    inline Point                           Instance :: getPosition () const { return position_; }
  inline Cell *                          Instance :: getMasterCell () const {  return masterCell_; }
    
    
}// Netlist namespace.

#endif //  NETLIST_INSTANCE_H
