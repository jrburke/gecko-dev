/* -*- Mode: IDL; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Mozilla browser.
 * 
 * The Initial Developer of the Original Code is Netscape
 * Communications, Inc.  Portions created by Netscape are
 * Copyright (C) 1999, Mozilla.  All Rights Reserved.
 * 
 * Contributor(s):
 *   Travis Bogard <travis@netscape.com>
 */

#ifndef nsWebBrowserChrome_h__
#define nsWebBrowserChrome_h__

// Helper Classes
#include "nsCOMPtr.h"

// Interfaces Needed
#include "nsIWebBrowserChrome.h"
#include "nsIDocShellTreeOwner.h"
#include "nsIBaseWindow.h"
#include "nsIInterfaceRequestor.h"

class nsBrowserWindow;

class nsWebBrowserChrome : public nsIWebBrowserChrome,
                           public nsIDocShellTreeOwner,
                           public nsIBaseWindow,
                           public nsIInterfaceRequestor
{
friend class nsBrowserWindow;

public:
   NS_DECL_ISUPPORTS

   NS_DECL_NSIWEBBROWSERCHROME
   
   NS_DECL_NSIDOCSHELLTREEOWNER
   // nsIDocShellTreeOwner
/*   NS_IMETHOD FindItemWithName(const PRUnichar* aName,
         nsIDocShellTreeItem* aRequestor, nsIDocShellTreeItem** aFoundItem);
   NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem* aContentShell,
         PRBool aPrimary, const PRUnichar* aID);
   NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem** aShell);
   NS_IMETHOD SizeShellTo(nsIDocShellTreeItem* aShell, PRInt32 aCX, PRInt32 aCY);
   NS_IMETHOD ShowModal();

   NS_IMETHOD GetNewBrowserChrome(PRInt32 aChromeFlags,
         nsIWebBrowserChrome** aWebBrowserChrome); */

   NS_DECL_NSIBASEWINDOW
   NS_DECL_NSIINTERFACEREQUESTOR

protected:
   nsWebBrowserChrome();
   virtual ~nsWebBrowserChrome();

   void BrowserWindow(nsBrowserWindow* aBrowserWindow);
   nsBrowserWindow* BrowserWindow();

protected:
   nsBrowserWindow*  mBrowserWindow;
};

#endif /* nsWebBrowserChrome_h__ */
