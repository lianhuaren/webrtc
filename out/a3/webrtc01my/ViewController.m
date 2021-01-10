//
//  ViewController.m
//  webrtc01my
//
//  Created by libb on 2021/1/5.
//

#import "ViewController.h"
#import "ARDVideoCallViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    UIButton *btn1 = [[UIButton alloc] initWithFrame:CGRectMake(100, 100, 200, 40)];
    [btn1 setTitle:@"打开" forState:UIControlStateNormal];
    [btn1 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btn1 setBackgroundColor:[UIColor grayColor]];
    [btn1 addTarget:self action:@selector(btn1Press:) forControlEvents:UIControlEventTouchUpInside];




    [self.view addSubview:btn1];

    
}

- (void)btn1Press:(id)sender
{
    int i = arc4random() % 99 ;
    
    NSString *trimmedRoom = [NSString stringWithFormat:@"%d",i];
    BOOL isLoopback = YES;
    
    // Kick off the video call.
    ARDVideoCallViewController *videoCallViewController =
        [[ARDVideoCallViewController alloc] initForRoom:trimmedRoom
                                             isLoopback:isLoopback
                                               delegate:self];
    videoCallViewController.modalTransitionStyle =
        UIModalTransitionStyleCrossDissolve;
    [self presentViewController:videoCallViewController
                       animated:YES
                     completion:nil];
}

#pragma mark - ARDVideoCallViewControllerDelegate

- (void)viewControllerDidFinish:(ARDVideoCallViewController *)viewController {
  if (![viewController isBeingDismissed]) {
//    RTCLog(@"Dismissing VC");
    [self dismissViewControllerAnimated:YES completion:^{
//      [self restartAudioPlayerIfNeeded];
    }];
  }
//  RTCAudioSession *session = [RTCAudioSession sharedInstance];
//  session.isAudioEnabled = NO;
}

@end
