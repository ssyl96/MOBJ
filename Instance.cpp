//
#include "Instance.h"
#include "cstdlib"
//#include<vector>
//#include"Net.h"
#include"Cell.h"
#include"Term.h"

namespace Netlist {
    using namespace std;
    
    class Cell;
    class Term;
    class Net;

  Instance :: Instance ( Cell * owner , Cell * model , const std :: string & name ) //on duplique (copie) les terminaux du modele de l'instance
    : owner_ (owner)
    , masterCell_ (model)
    , name_ (name)
    , terms_ ()
    , position_ ()
    {
      const vector <Term*> & terms = masterCell_ -> getTerms ();
      for (vector<Term*>:: const_iterator iterm= terms.begin(); iterm!=terms.end(); ++iterm)
        {
          new Term(this, *iterm); //création du terminal de l'instance
        }
      owner_->add (this); //ajout de l'instance dans la liste des instances du modele en construction 
    }
    Instance :: ~Instance ()
    {
    /* for ( vector<Term*>::iterator iterm=terms_.begin() ; iterm != terms_.end() ; ++iterm ) {
         if (*iinst == this) {
           terms_.erase( iterm );
           break;
         }
         }
       while ( not nets_     .empty() ) delete *nets_     .begin();
       while ( not instances_.empty() ) delete *instances_.begin();*/
       while ( not terms_    .empty() ) delete *terms_    .begin();
    }

    Term * Instance :: getTerm ( const std :: string & term ) const
    {
       for ( vector<Term*>::const_iterator iterm=terms_.begin() ; iterm != terms_.end() ; ++iterm ) {
         if ((*iterm)->getName() == term)
           return *iterm;
       }
       return NULL;
    }
  
    bool Instance :: connect ( const std :: string & name , Net* net)
    {
        Term* term = getTerm (name);
        if (term == NULL) return false;
        term->setNet (net);
        return true;
    }
    void Instance :: add ( Term * term )
    {
        if (getTerm(term->getName())) {
            cerr << "[ERROR] Attemp to add duplicated terminal <" << term->getName() << ">." << endl;
            exit( 1 );
        }
        terms_.push_back (term);
    }
    void Instance :: remove ( Term * term)
    {
        for (vector<Term*>::iterator iterm=terms_.begin(); iterm!=terms_.end(); ++iterm)
        {
            if (*iterm==term) terms_.erase (iterm);
        }
        
    }
    void Instance :: setPosition ( const Point & point )
    {
      position_=point;
    }
    void Instance :: setPosition ( int x , int y )
    {
      Point (x , y);
    }
}
