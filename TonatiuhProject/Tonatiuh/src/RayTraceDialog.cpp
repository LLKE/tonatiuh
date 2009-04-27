/***************************************************************************
Copyright (C) 2008 by the Tonatiuh Software Development Team.

This file is part of Tonatiuh.

Tonatiuh program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Acknowledgments:

The development of Tonatiuh was started on 2004 by Dr. Manuel J. Blanco,
then Chair of the Department of Engineering of the University of Texas at
Brownsville. From May 2004 to July 2008, it was supported by the Department
of Energy (DOE) and the National Renewable Energy Laboratory (NREL) under
the Minority Research Associate (MURA) Program Subcontract ACQ-4-33623-06.
During 2007, NREL also contributed to the validation of Tonatiuh under the
framework of the Memorandum of Understanding signed with the Spanish
National Renewable Energy Centre (CENER) on February, 20, 2007 (MOU#NREL-07-117).
Since June 2006, the development of Tonatiuh is being led by the CENER, under the
direction of Dr. Blanco, now Director of CENER Solar Thermal Energy Department.

Developers: Manuel J. Blanco (mblanco@cener.com), Amaia Mutuberria, Victor Martin.

Contributors: Javier Garcia-Barberena, I�aki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#include <QAbstractButton>
#include <QFileDialog>
#include <QDir>

#include "RayTraceDialog.h"
#include "Trace.h"

/**
 * Creates a dialog to ray tracer options with the given \a parent and \a f flags.
 *
 * The variables take the default values.
 */
RayTraceDialog::RayTraceDialog( QWidget * parent, Qt::WindowFlags f )
:QDialog ( parent, f )
{
	Trace( "RayTraceDialog::RayTraceDialog", false );

	setupUi( this );
	connect( this, SIGNAL( accepted() ), this, SLOT( saveChanges() ) );
	connect( buttonBox, SIGNAL( clicked( QAbstractButton* ) ), this, SLOT( applyChanges( QAbstractButton* ) ) );
}

/**
 * Creates a dialog to ray tracer options with the given \a parent and \a f flags.
 *
 * The variables take the values specified by \a numRats, \a faction, \a drawPhotons and \a increasePhotonMap.
 */
RayTraceDialog::RayTraceDialog( int numRays, double fraction, bool drawPhotons, bool increasePhotonMap, QWidget * parent, Qt::WindowFlags f )
:QDialog ( parent, f ), m_numRays( numRays ), m_fraction( fraction ), m_increasePhotonMap( increasePhotonMap ), m_drawPhotons( drawPhotons )
{
	Trace( "RayTraceDialog::RayTraceDialog", false );

	setupUi( this );
	raysSpinBox->setValue( m_numRays );
	drawSpinBox->setValue( m_fraction );
	photonsCheckBox->setChecked( m_drawPhotons );

	if ( m_increasePhotonMap )
		increaseMapRadioButton->setChecked( true );
	else
		newMapRadioButton->setChecked( true );

	connect( this, SIGNAL( accepted() ), this, SLOT( saveChanges() ) );
	connect( buttonBox, SIGNAL( clicked( QAbstractButton* ) ), this, SLOT( applyChanges() ) );
}

/*!
 * Destroys the RayTraceDialog object.
 */
RayTraceDialog::~RayTraceDialog()
{
	Trace( "RayTraceDialog::~RayTraceDialog", false );
}

/**
 * If the applyChanges button is clicked the dialog values are saved.
 */
void RayTraceDialog::applyChanges( QAbstractButton* button  )
{
	Trace( "RayTraceDialog::applyChanges", false );
	if( buttonBox->buttonRole( button ) == 8 ) saveChanges();
}

/**
 * Saves the values of the dialog.
 */
void RayTraceDialog::saveChanges()
{
	Trace( "RayTraceDialog::saveChanges", false );

	m_numRays = raysSpinBox->value();

	m_fraction = drawSpinBox->value();
	m_drawPhotons = photonsCheckBox->isChecked();

	if( newMapRadioButton->isChecked() )
		m_increasePhotonMap = false;
	else
		m_increasePhotonMap = true;
}
