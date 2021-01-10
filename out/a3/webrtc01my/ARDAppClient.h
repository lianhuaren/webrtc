//
//  ARDAppClient.h
//  webrtc01my
//
//  Created by libb on 2021/1/5.
//

#import <Foundation/Foundation.h>
#import "ARDSettingsModel.h"
#import "WebRTC/RTCCameraVideoCapturer.h"
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ARDAppClientState) {
  // Disconnected from servers.
  kARDAppClientStateDisconnected,
  // Connecting to servers.
  kARDAppClientStateConnecting,
  // Connected to servers.
  kARDAppClientStateConnected,
};
@class ARDAppClient;

// The delegate is informed of pertinent events and will be called on the
// main queue.
@protocol ARDAppClientDelegate <NSObject>

//- (void)appClient:(ARDAppClient *)client
//    didChangeState:(ARDAppClientState)state;
//
//- (void)appClient:(ARDAppClient *)client
//    didChangeConnectionState:(RTCIceConnectionState)state;
//
- (void)appClient:(ARDAppClient *)client
    didCreateLocalCapturer:(RTCCameraVideoCapturer *)localCapturer;
//
//- (void)appClient:(ARDAppClient *)client
//    didReceiveLocalVideoTrack:(RTCVideoTrack *)localVideoTrack;
//
//- (void)appClient:(ARDAppClient *)client
//    didReceiveRemoteVideoTrack:(RTCVideoTrack *)remoteVideoTrack;

- (void)appClient:(ARDAppClient *)client
         didError:(NSError *)error;

- (void)appClient:(ARDAppClient *)client
      didGetStats:(NSArray *)stats;

@optional
//- (void)appClient:(ARDAppClient *)client
//didCreateLocalFileCapturer:(RTCFileVideoCapturer *)fileCapturer;

@end

@interface ARDAppClient : NSObject
@property(nonatomic, assign) ARDAppClientState state;
@property(nonatomic, weak) id<ARDAppClientDelegate> delegate;

- (void)connectToRoomWithId:(NSString *)roomId
                   settings:(ARDSettingsModel *)settings
                 isLoopback:(BOOL)isLoopback;

@end

NS_ASSUME_NONNULL_END
