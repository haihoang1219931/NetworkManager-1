/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 * Copyright (C) 2013 Jiri Pirko <jiri@resnulli.us>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 */

#ifndef NM_DEVICE_TEAM_H
#define NM_DEVICE_TEAM_H

#include "nm-device.h"

G_BEGIN_DECLS

#define NM_TYPE_DEVICE_TEAM            (nm_device_team_get_type ())
#define NM_DEVICE_TEAM(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), NM_TYPE_DEVICE_TEAM, NMDeviceTeam))
#define NM_DEVICE_TEAM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), NM_TYPE_DEVICE_TEAM, NMDeviceTeamClass))
#define NM_IS_DEVICE_TEAM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NM_TYPE_DEVICE_TEAM))
#define NM_IS_DEVICE_TEAM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NM_TYPE_DEVICE_TEAM))
#define NM_DEVICE_TEAM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), NM_TYPE_DEVICE_TEAM, NMDeviceTeamClass))

/**
 * NMDeviceTeamError:
 * @NM_DEVICE_TEAM_ERROR_UNKNOWN: unknown or unclassified error
 * @NM_DEVICE_TEAM_ERROR_NOT_TEAM_CONNECTION: the connection was not of team type
 * @NM_DEVICE_TEAM_ERROR_INVALID_TEAM_CONNECTION: the team connection was invalid
 * @NM_DEVICE_TEAM_ERROR_INTERFACE_MISMATCH: the interfaces of the connection and the device mismatched
 */
typedef enum {
	NM_DEVICE_TEAM_ERROR_UNKNOWN = 0,             /*< nick=UnknownError >*/
	NM_DEVICE_TEAM_ERROR_NOT_TEAM_CONNECTION,     /*< nick=NotTeamConnection >*/
	NM_DEVICE_TEAM_ERROR_INVALID_TEAM_CONNECTION, /*< nick=InvalidTeamConnection >*/
	NM_DEVICE_TEAM_ERROR_INTERFACE_MISMATCH,      /*< nick=InterfaceMismatch >*/
} NMDeviceTeamError;

#define NM_DEVICE_TEAM_ERROR nm_device_team_error_quark ()
NM_AVAILABLE_IN_0_9_10
GQuark nm_device_team_error_quark (void);

#define NM_DEVICE_TEAM_HW_ADDRESS  "hw-address"
#define NM_DEVICE_TEAM_CARRIER     "carrier"
#define NM_DEVICE_TEAM_SLAVES      "slaves"

typedef struct {
	NMDevice parent;
} NMDeviceTeam;

typedef struct {
	NMDeviceClass parent;

	/* Padding for future expansion */
	void (*_reserved1) (void);
	void (*_reserved2) (void);
	void (*_reserved3) (void);
	void (*_reserved4) (void);
	void (*_reserved5) (void);
	void (*_reserved6) (void);
} NMDeviceTeamClass;

NM_AVAILABLE_IN_0_9_10
GType nm_device_team_get_type (void);

NM_AVAILABLE_IN_0_9_10
GObject *nm_device_team_new (DBusGConnection *connection, const char *path);

const char      *nm_device_team_get_hw_address (NMDeviceTeam *device);
gboolean         nm_device_team_get_carrier    (NMDeviceTeam *device);
const GPtrArray *nm_device_team_get_slaves     (NMDeviceTeam *device);

G_END_DECLS

#endif /* NM_DEVICE_TEAM_H */
