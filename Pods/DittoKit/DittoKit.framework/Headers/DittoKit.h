//
//  DittoKit.h
//  Ditto
//
//  Created by Hamilton Chapman on 05/02/2019.
//  Copyright © 2019 Ditto. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for DittoKit.
FOUNDATION_EXPORT double DittoKitVersionNumber;

//! Project version string for DittoKit.
FOUNDATION_EXPORT const unsigned char DittoKitVersionString[];

// General
#import <DittoKit/DITDBConfig.h>
#import <DittoKit/DITDittoKit.h>
#import <DittoKit/DITDittoKitDelegate.h>
#import <DittoKit/DITErrors.h>
#import <DittoKit/DITIdentity.h>
#import <DittoKit/DITLogLevel.h>

// Store
#import <DittoKit/DITAttachment.h>
#import <DittoKit/DITAttachmentFetcher.h>
#import <DittoKit/DITAttachmentStatus.h>
#import <DittoKit/DITAttachmentToken.h>
#import <DittoKit/DITCollection.h>
#import <DittoKit/DITDocument.h>
#import <DittoKit/DITDocumentPath.h>
#import <DittoKit/DITLiveQuery.h>
#import <DittoKit/DITLiveQueryEvent.h>
#import <DittoKit/DITLiveQueryMove.h>
#import <DittoKit/DITMutableDocument.h>
#import <DittoKit/DITMutableDocumentPath.h>
#import <DittoKit/DITPendingCursorOperation.h>
#import <DittoKit/DITPendingIDSpecificOperation.h>
#import <DittoKit/DITScopedWriteTransaction.h>
#import <DittoKit/DITSingleDocumentLiveQueryEvent.h>
#import <DittoKit/DITSortDirection.h>
#import <DittoKit/DITStore.h>
#import <DittoKit/DITSubscription.h>
#import <DittoKit/DITUpdateResult.h>
#import <DittoKit/DITWriteTransaction.h>
#import <DittoKit/DITWriteTransactionPendingCursorOperation.h>
#import <DittoKit/DITWriteTransactionPendingIDSpecificOperation.h>
#import <DittoKit/DITWriteTransactionResult.h>

// Transport
#import <DittoKit/DITPeersObserver.h>
#import <DittoKit/DITRemotePeer.h>
#import <DittoKit/DITTransport.h>
#import <DittoKit/DITTransportCondition.h>
#import <DittoKit/DITTransportDiagnostics.h>
#import <DittoKit/DITTransportSnapshot.h>
