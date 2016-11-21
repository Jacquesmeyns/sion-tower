/*
 * This file is part of SionTower.
 *
 * 
 * David Saltares Marquez (C) 2011
 * <david.saltares@gmail.com>
 *
 * 
 * SionTower examples are free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License ad
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) ant later version.
 *
 * SionTower examples are distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SionTower examples.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef SIONTOWER_TRUNK_SRC_INCLUDE_STATEPROFILE_H_
#define SIONTOWER_TRUNK_SRC_INCLUDE_STATEPROFILE_H_

#include <vector>

#include <OGRE/Ogre.h>
#include <MYGUI/MyGUI.h>

#include "state.h"
#include "song.h"
#include "soundFX.h"


class ProfileManager;
class Level;

//! Estado para la pantalla de selección de perfil

/**
 * @author David Saltares Márquez
 * @date 22-06-2011
 * 
 * Clase que modela el estado para la pantalla de selección de perfil,
 * incluye elementos de la interfaz, lógica y escena tridimensional.
 */
class StateProfile: public State {
    public:
    
        /**
         * Constructor
         * 
         * @param stateManager gestor de estados que controla el estado
         */
        StateProfile(StateManager* stateManager);
        
        /**
         * Destructor
         */
        ~StateProfile();
        
        /**
         * Carga todos los elementos del estado: escenario, GUI... Se
         * encarga de las traducciones y ajustar tamaños.
         */
        void load();
        
        /**
         * Libera los recursos que consume la escena
         */
        void clear();
        
        /**
         * Actualiza de forma lógica la escena
         * 
         * @param deltaT tiempo en segundos desde el último cuadro
         * @param active true si es el estado activo
         */
        void update(Ogre::Real deltaT, bool active);
        
        /**
         * Evento de pulsación de tecla
         * 
         * @param arg información del evento
         * @return true si todo ha ido bien
         */
        bool keyPressed(const OIS::KeyEvent &arg);
        
        /**
         * Evento de liberación de tecla
         * 
         * @param arg información del evento
         * @return true si todo ha ido bien
         */
        bool keyReleased(const OIS::KeyEvent &arg);
        
        /**
         * Evento de movimiento de ratón
         * 
         * @param arg información del evento
         * @return true si todo ha ido bien
         */
        bool mouseMoved(const OIS::MouseEvent &arg);
        
        /**
         * Evento de pulsación de un botón del ratón
         * 
         * @param arg información del evento
         * @param id botón con el que se ha interactuado
         * @return true si todo ha ido bien
         */
        bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
        
        /**
         * Evento de liberación de un botón del ratón
         * 
         * @param arg información del evento
         * @param id botón con el que se ha interactuado
         * @return true si todo ha ido bien
         */
        bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
        
        /**
         * Manejador del evento que se activa al pulsar sobre el botón "atrás"
         * 
         * @param sender elemento de MyGUI que recibe el evento
         */
        void btnBackClicked(MyGUI::WidgetPtr sender);
        
        /**
         * Manejador del evento que se activa al pulsar sobre el botón "crear perfil"
         * 
         * @param sender elemento de MyGUI que recibe el evento
         */
        void btnCreateClicked(MyGUI::WidgetPtr sender);
        
        /**
         * Manejador del evento que se activa al pulsar sobre el botón "aceptar"
         * 
         * @param sender elemento de MyGUI que recibe el evento
         */
        void btnAcceptClicked(MyGUI::WidgetPtr sender);
        
        /**
         * Manejador del evento que se activa al pulsar sobre el botón "eliminar perfil"
         * 
         * @param sender elemento de MyGUI que recibe el evento
         */
        void btnDeleteClicked(MyGUI::WidgetPtr sender);
        
        /**
         * Manejador del evento que se activa al seleccionar un perfil de la lista
         * 
         * @param sender elemento de MyGUI que recibe el evento
         * @param index índice del elemento de la lista seleccionado
         */
        void listItemAccepted(MyGUI::WidgetPtr sender, size_t index);
        
        /**
         * Manejador del evento que se activa cuando un botón obtiene el foco
         * 
         * @param sender elemento de MyGUI que recibe el foco
         * @param old elemento de MyGUI que pierde el foco
         */
        void btnMouseFocus(MyGUI::Widget* sender, MyGUI::Widget* old);
        
    private:
        // Música
        SongPtr _song;
        
        // Interfaz
        MyGUI::Gui* _myGUI;
        MyGUI::VectorWidgetPtr _widgetLayout;
        MyGUI::Button* _btnBack;
        MyGUI::Button* _btnAccept;
        MyGUI::Button* _btnCreate;
        MyGUI::Button* _btnDelete;
        MyGUI::Edit* _editName;
        MyGUI::TextBox* _lblErrorCreate;
        MyGUI::TextBox* _lblErrorDelete;
        MyGUI::ListBox* _listProfiles;
        MyGUI::TextBox* _lblExperience;
        MyGUI::TextBox* _lblExperience2;
        MyGUI::TextBox* _lblLevels;
        MyGUI::TextBox* _lblLevels2;
        MyGUI::TextBox* _lblProfileSel;
        MyGUI::TextBox* _lblProfileCreation;
        MyGUI::TextBox* _lblName;
        MyGUI::TextBox* _lblSubtitle;
        
        // Sonido
        SoundFXPtr _optionOver;
        SoundFXPtr _optionSelected;
        SoundFXPtr _optionError;
        
        // Gestor de perfiles
        ProfileManager* _profileManager;
        
        // Geometría
        Level* _level;
        
        // Personajes
        std::vector<Ogre::AnimationState*> _charactersAnimations;
        std::vector<Ogre::SceneNode*> _charactersNodes;
        std::vector<Ogre::Entity*> _charactersEntities;
        void loadCharacters();
        void unloadCharacters();
        
        // Recuperar datos
        void retrieveData(size_t index);
        
        // Traducción
        virtual void translate();
        
        // Altura del texto
        virtual void adjustFontHeight();
};


#endif  // SIONTOWER_TRUNK_SRC_INCLUDE_STATEPROFILE_H_
