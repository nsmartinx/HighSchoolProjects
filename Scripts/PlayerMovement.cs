using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public CharacterController2D controller;
    float horizontal;
    public float speed = 40;
    bool jump;
    public Animator animator;

    // Update is called once per frame
    void Update()
    {
        horizontal = Input.GetAxisRaw("Horizontal");
        if (horizontal == 0)
        {
            animator.SetBool("IsMoving", false);
        }
        else
        {
            animator.SetBool("IsMoving", true);
        }
        if (Input.GetButtonDown("Jump"))
            jump = true;
        
    }

    void FixedUpdate()
    {
        controller.Move(horizontal * speed * Time.fixedDeltaTime, false, jump);
        jump = false;
    }
}
