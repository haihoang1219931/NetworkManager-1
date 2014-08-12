/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
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
 *
 * Copyright 2007 - 2008 Novell, Inc.
 * Copyright 2007 - 2014 Red Hat, Inc.
 */

#include "nm-simple-connection.h"

static void nm_simple_connection_interface_init (NMConnectionInterface *iface);

G_DEFINE_TYPE_WITH_CODE (NMSimpleConnection, nm_simple_connection, G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (NM_TYPE_CONNECTION, nm_simple_connection_interface_init);
                         )

static void
nm_simple_connection_init (NMSimpleConnection *self)
{
}

/**
 * nm_simple_connection_new:
 *
 * Creates a new #NMSimpleConnection object with no #NMSetting objects. An
 * #NMSimpleConnection does not directly represent a D-Bus-exported connection,
 * but might be used in the process of creating a new one.
 *
 * Returns: (transfer full): the new empty #NMConnection object
 **/
NMConnection *
nm_simple_connection_new (void)
{
	return (NMConnection *) g_object_new (NM_TYPE_SIMPLE_CONNECTION, NULL);
}

/**
 * nm_simple_connection_new_from_hash:
 * @hash: (element-type utf8 GLib.HashTable): the #GHashTable describing
 * the connection
 * @error: on unsuccessful return, an error
 *
 * Creates a new #NMSimpleConnection from a hash table describing the
 * connection.  See nm_connection_to_hash() for a description of the expected
 * hash table.
 *
 * Returns: (transfer full): the new #NMSimpleConnection object, populated with
 * settings created from the values in the hash table, or %NULL if the
 * connection failed to validate
 **/
NMConnection *
nm_simple_connection_new_from_hash (GHashTable *hash, GError **error)
{
	NMConnection *connection;

	g_return_val_if_fail (hash != NULL, NULL);

	connection = nm_simple_connection_new ();
	if (!nm_connection_replace_settings (connection, hash, error)) {
		g_object_unref (connection);
		return NULL;
	}
	return connection;
}

/**
 * nm_simple_connection_new_clone:
 * @connection: the #NMConnection to clone
 *
 * Clones an #NMConnection as an #NMSimpleConnection.
 *
 * Returns: (transfer full): a new #NMConnection containing the same settings
 * and properties as the source #NMConnection
 **/
NMConnection *
nm_simple_connection_new_clone (NMConnection *connection)
{
	NMConnection *clone;

	g_return_val_if_fail (NM_IS_CONNECTION (connection), NULL);

	clone = nm_simple_connection_new ();
	nm_connection_set_path (clone, nm_connection_get_path (connection));
	nm_connection_replace_settings_from_connection (clone, connection, NULL);

	return clone;
}

static void
nm_simple_connection_class_init (NMSimpleConnectionClass *simple_class)
{
}

static void
nm_simple_connection_interface_init (NMConnectionInterface *iface)
{
}